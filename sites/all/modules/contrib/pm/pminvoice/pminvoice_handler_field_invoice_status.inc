<?php
/**
 * @file
 * Handler for the Project Management Invoice status field in Views
 */

/**
 * Field handler for invoice status.
 */
class pminvoice_handler_field_invoice_status extends views_handler_field {

  /**
   * Constructor method.
   */
  function construct() {
    parent::construct();
    $this->additional_fields['paymentdate'] = array('field' => 'paymentdate');
    $this->additional_fields['duedate'] = array('field' => 'duedate');
  }

  /**
   * Add fields to query.
   */
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Override render method.
   */
  function render($values) {
    $paymentdate = $values->{$this->aliases['paymentdate']};
    $duedate = $values->{$this->aliases['duedate']};
    $status = 'open';
    if ($paymentdate) {
      $status = 'paid';
    }
    elseif ($duedate < time()) {
      $status = 'overdue';
    }
    return pm_icon('invoice_status_' . check_plain($status), pm_attribute_value('Invoice status', $status));
  }

}
