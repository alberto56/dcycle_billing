<?php
/**
 * @file
 * Theme functions for PM Invoice.
 */

/**
 * Returns the HTML code for the invoice view page
 *
 * @param $node
 *   The node object that contains the invoice.
 * @param $teaser
 *   True if the teaser is showed.
 * @param $page
 *   True if the full page is showed.
 * @return
 *   The node object that contains the invoice.
 */
function theme_pminvoice_view($variables) {
  $node = $variables['node'];
  $view_mode = $variables['view_mode'];

  $node->content['group1'] = array(
    '#prefix' => '<div class="field">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group1') : -20,
  );

  $node->content['group1']['number'] = array(
    '#prefix' => '<div class="number">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Number'), 'value' => $node->number)),
    '#weight' => 1,
  );

  $node->content['group2'] = array(
    '#prefix' => '<div class="field">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group2') : -19,
  );

  $node->content['group2']['organization'] = array(
    '#prefix' => '<div class="organization">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Organization'), 'value' => l($node->organization_title, 'node/' . $node->organization_nid))),
    '#weight' => 1,
  );

  $node->content['group2']['project'] = array(
    '#prefix' => '<div class="project">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Project'), 'value' => l($node->project_title, 'node/' . $node->project_nid))),
    '#weight' => 2,
  );

  if ($node->reference) {
    $node->content['group2']['reference'] = array(
      '#prefix' => '<div class="reference">',
      '#suffix' => '</div>',
      '#markup' => theme('pm_view_item', array('label' => t('Reference'), 'value' => check_plain($node->reference))),
      '#weight' => 3,
    );
  }

  $node->content['group3'] = array(
    '#prefix' => '<div class="field">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group3') : -18,
  );

  $status = 'open';
  if (isset($node->pminvoice_paymentdate[LANGUAGE_NONE][0]['value'])) {
    $status = 'paid';
  }
  elseif ($node->pminvoice_duedate[LANGUAGE_NONE][0]['value'] < time()) {
    $status = 'overdue';
  }
  $node->content['group3']['status'] = array(
    '#prefix' => '<div class="invoicestatus">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Status'), 'value' => $status)),
    '#weight' => 4,
  );

  // Processing for invoice items.
  $header = array(
    array(
      'data' => t('Item'),
    ),
    array(
      'data' => t('Amount'),
      // 'style' => 'text-align: right;',
    ),
  );

  if ($node->tax1) {
    $header[] = array(
      'data' => t(variable_get('pm_tax1_name', 'Tax 1')),
      // 'style' => 'text-align: right;',
    );
  }

  if ($node->tax2) {
    $header[] = array(
      'data' => t(variable_get('pm_tax2_name', 'Tax 2')),
      // 'style' => 'text-align: right;',
    );
  }

  $header[] = array(
      'data' => t('Total'),
      // 'style' => 'text-align: right;',
    );

  $where = array();
  $s  = "SELECT sit.description, sit.amount, ";
  if ($node->tax1) {
    $s .= "sit.tax1, ";
  }
  if ($node->tax2) {
    $s .= "sit.tax2, ";
  }
  $s .= "sit.total, sit.src_nid FROM {pminvoice_items} sit WHERE sit.invoice_vid=%d ORDER BY sit.weight ASC";
  // $r = db_query($s, $node->vid);

  $invoice_items = array();
  $i = 0;
  while (0) {
    // $invoice_item = db_fetch_array($r)) {
    $invoice_items[$i] = $invoice_item;
    $i++;
  }

  foreach ($invoice_items as $key => $inv_item) {
    // PHP4 compatibility - for D7 change this to use the original array by reference
    $invoice_items[$key]['amount'] = sprintf("%.2f", $inv_item['amount']);
    if ($node->tax1) {
    $invoice_items[$key]['tax1'] = sprintf("%.2f", $inv_item['tax1']);
    }
    if ($node->tax2) {
    $invoice_items[$key]['tax2'] = sprintf("%.2f", $inv_item['tax2']);
    }
    $invoice_items[$key]['total'] = sprintf("%.2f", $inv_item['total']);
    if ($invoice_items[$key]['src_nid'] != 0 AND $invoice_items[$key]['src_nid'] != NULL) {
      $invoice_items[$key]['description'] = l(t($invoice_items[$key]['description']), 'node/' . $inv_item['src_nid']);
    }
    unset($invoice_items[$key]['src_nid']);
  }

  $node->content['group4'] = array(
    '#prefix' => '<div class="field">',
    '#markup' => theme('table', $header, $invoice_items),
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group4') : -17,
  );

  $node->content['group5'] = array(
    '#prefix' => '<div class="field">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group5') : -16,
  );

  $node->content['group5']['amount'] = array(
    '#prefix' => '<div class="amount">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Amount'), 'value' => sprintf('%.2f', $node->amount))),
    '#weight' => 1,
  );

  if ($node->tax1) {
  $node->content['group5']['tax1'] = array(
    '#prefix' => '<div class="tax">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t(variable_get('pm_tax1_name', 'Tax 1')), 'value' => sprintf('%.2f', $node->tax1))),
    '#weight' => 2,
  );
  }

  if ($node->tax2) {
  $node->content['group5']['tax2'] = array(
    '#prefix' => '<div class="tax">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t(variable_get('pm_tax2_name', 'Tax 2')), 'value' => sprintf('%.2f', $node->tax2))),
    '#weight' => 3,
  );
  }

  $node->content['group5']['total'] = array(
    '#prefix' => '<div class="total">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Total'), 'value' => sprintf('%.2f', $node->total))),
    '#weight' => 4,
  );

  $organization = node_load($node->organization_nid);
  $myorg = node_load(variable_get('pm_organization_nid', 0));
  if (isset($myorg->orglanguage)) {
    if ($myorg->orglanguage != $organization->orglanguage) {
      $language = $organization->orglanguage . ',' . $myorg->orglanguage;
    }
    else {
      $language = $myorg->orglanguage;
    }
  }

  if (isset($myorg->currency)) {
    $currencies = pm_attributes_bydomain('Currency');
    $node->content['group5']['currency'] = array(
      '#prefix' => '<div class="currency">',
      '#suffix' => '</div>',
      '#markup' => t('Unless stated, amounts shown on this invoice are quoted in %currency.', array('%currency' => $currencies['values'][$myorg->currency])),
      '#weight' => 5,
    );
  }

  $body = field_get_items('node', $node, 'body');
  if ($body) {
    $node->content['body'] = array(
      '#prefix' => '<div class="pmbody">',
      '#suffix' => '</div>',
      '#markup' => theme('pm_view_item', array('label' => t('Description'), 'value' => $body[0]['safe_value'])),
      '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'body_field') : -18,
    );
  }

  return $node;
}
