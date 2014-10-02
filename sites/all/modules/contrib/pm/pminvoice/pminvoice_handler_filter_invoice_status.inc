<?php
/**
 * @file
 * Handler for the Project Management Invoice status filter in views
 */

/**
 * Filter handler for invoice status.
 */
class pminvoice_handler_filter_invoice_status extends views_handler_filter_in_operator {
  var $value_form_type = 'radios';

  /**
   * Options for filter values.
   */
  function get_value_options() {
    $this->value_options = array(
      'to pay' => t('to pay'),
      'paid' => t('paid'),
      'overdue' => t('overdue'),
    );
  }

  /**
   * Available operators for this filter.
   */
  function operators() {
    $operators = array(
      'in' => array(
        'title' => t('Is one of'),
        'short' => t('in'),
        'short_single' => t('='),
        'method' => 'op_simple',
        'values' => 1,
      ),
    );
    return $operators;
  }

  /**
   * If default_value is array, use the first value.
   */
  function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);
    if (isset($form['value']) && is_array($form['value']['#default_value'])) {
      $form['value']['#default_value'] = $form['value']['#default_value'][0];
    }
  }

  /**
   * Override expose_form_right method.
   */
  function expose_form_right(&$form, &$form_state) {
    parent::expose_form_right($form, $form_state);
    unset($form['expose']['reduce']);
    $form['expose']['reduce'] = array(
      '#type' => 'value',
      '#value' => 0,
    );
  }

  /**
   * Build filter query.
   */
  function op_simple() {
    if (empty($this->value)) {
      return;
    }

    $this->ensure_my_table();

    $args = array();
    if ($this->value == 'to pay') {
      $where = $this->table_alias . ".paymentdate=%d AND " . $this->table_alias . ".duedate >= %d";
      $args[] = 0;
      $args[] = time();
    }
    elseif ($this->value == 'paid') {
      $where = $this->table_alias . ".paymentdate<>%d";
      $args[] = 0;
    }
    // Case that invoice is overdue.
    else {
      $where = $this->table_alias . ".paymentdate=%d AND " . $this->table_alias . ".duedate < %d";
      $args[] = 0;
      $args[] = time();
    }

    $this->query->add_where($this->options['group'], $where, $args);
  }

}
