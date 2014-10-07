<?php
/**
 * @file
 * manage_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function manage_feature_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'commerce_line_item-product-field_dcycle_line_item_desc'
  $field_instances['commerce_line_item-product-field_dcycle_line_item_desc'] = array(
    'bundle' => 'product',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_dcycle_line_item_desc',
    'label' => 'Description',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Description');

  return $field_instances;
}
