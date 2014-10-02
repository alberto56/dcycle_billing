<?php
/**
 * @file
 */
function theme_pmorganization_view($variables) {
  $node = $variables['node'];

  drupal_add_css(drupal_get_path('module', 'pm') . '/pm-node.css');

  $node->content['group2'] = array(
    '#prefix' => '<div class="pmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group2') : -19,
  );

  $node->content['group3'] = array(
    '#prefix' => '<div class="pmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group3') : -18,
  );

  $node->content['group3']['address'] = array(
    '#prefix' => '<div class="address">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Address'), 'value' => check_plain($node->address))),
    '#weight' => 1,
  );

  $node->content['group3']['city'] = array(
    '#prefix' => '<div class="city">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('City'), 'value' => check_plain($node->city))),
    '#weight' => 2,
  );

  $node->content['group3']['provstate'] = array(
    '#prefix' => '<div class="provstate">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Province / State'), 'value' => check_plain($node->provstate))),
    '#weight' => 3,
  );

  $node->content['group3'] ['country'] = array(
    '#prefix' => '<div class="country">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Country'), 'value' => check_plain($node->country))),
    '#weight' => 4,
  );

  $node->content['group3'] ['zip'] = array(
    '#prefix' => '<div class="zip">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Zip'), 'value' => check_plain($node->zip))),
    '#weight' => 5,
  );

  $node->content['group4'] = array(
    '#prefix' => '<div class="pmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group4') : -17,
  );

  $node->content['group4']['phone'] = array(
    '#prefix' => '<div class="phone">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Phone'), 'value' => check_plain($node->phone))),
    '#weight' => 1,
  );

  $node->content['group4']['www'] = array(
    '#prefix' => '<div class="www">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('WWW'), 'value' => l($node->www, 'http://' . $node->www, array('absolute' => TRUE)))),
    '#weight' => 2,
  );

  $node->content['group4']['mail'] = array(
    '#prefix' => '<div class="mail">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('E-mail'), 'value' => l($node->email, 'mailto:' . $node->email, array('absolute' => TRUE)))),
    '#weight' => 3,
  );

  $node->content['group5'] = array(
    '#prefix' => '<div class="pmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group5') : -16,
  );

  $node->content['group5']['currency'] = array(
    '#prefix' => '<div class="currency">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Currency'), 'value' => check_plain($node->currency))),
    '#weight' => 1,
  );

  $languages = language_list('language', TRUE);
  $languages_options = array();
  foreach ($languages as $language_code => $language) {
    $languages_options[$language_code] = $language->name;
  }

  $node->content['group5']['language'] = array(
    '#prefix' => '<div class="language">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Language'), 'value' => check_plain($languages_options[$node->orglanguage]))),
    '#weight' => 2,
  );

  $node->content['group5'] ['taxid'] = array(
    '#prefix' => '<div class="taxid">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Tax ID'), 'value' => check_plain($node->taxid))),
    '#weight' => 3,
  );
  $body = field_get_items('node', $node, 'body');
  if ($body) {
    $node->content['body'] = array(
      '#prefix' => '<div class="pmbody">',
      '#suffix' => '</div>',
      '#markup' => theme('pm_view_item', array('label' => t('Description'), 'value' => $body[0]['safe_value'])),
      '#weight' => 4,
    );
  }

  return $node;
}
