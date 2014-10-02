<?php
/**
 * @file
 * Functions to expose Project Management Project data to the views module
 */

/**
 * Implements hook_views_data().
 */
function pmproject_views_data() {
  $data['pmproject']['table']['group']  = 'Project Management Project';
  $data['pmproject']['table']['join'] = array(
    'node' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
  );

  $data['pmproject']['organization_nid'] = array(
    'title' => t('Organization'),
    'help' => t('Project -> Organization'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Project -> Organization'),
    ),
  );

  $data['pmproject']['organization_title'] = array(
    'title' => t('Organization'),
    'help' => t('Project Management Project Organization (title only)'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['pmproject']['projectstatus'] = array(
    'title' => t('Status'),
    'help' => t('Project Management Project Status'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'pm_handler_field_attributes_domain',
      'domain' => 'Project Status',
      'icon' => 'status',
    ),
    'filter' => array(
      'handler' => 'pm_handler_filter_attributes_domain',
      'domain' => 'Project Status',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['pmproject']['projectcategory'] = array(
    'title' => t('Category'),
    'help' => t('Project Management Project Category'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'pm_handler_field_attributes_domain',
      'domain' => 'Project Category',
      'icon' => 'projectcategory',
    ),
    'filter' => array(
      'handler' => 'pm_handler_filter_attributes_domain',
      'domain' => 'Project Category',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['pmproject']['projectpriority'] = array(
    'title' => t('Priority'),
    'help' => t('Project Management Project Priority'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'pm_handler_field_attributes_domain',
      'domain' => 'Project Priority',
      'icon' => 'priority'
    ),
    'filter' => array(
      'handler' => 'pm_handler_filter_attributes_domain',
      'domain' => 'Project Priority',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['pmproject']['pricemode'] = array(
    'title' => t('Price mode'),
    'help' => t('Project Management Project Price Mode'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['pmproject']['price'] = array(
    'title' => t('Price'),
    'help' => t('Project Management Project Price'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['pmproject']['currency'] = array(
    'title' => t('Currency'),
    'help' => t('Project Management Project Currency'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['pmproject']['duration unit'] = array(
    'title' => t('Duration unit'),
    'help' => t('Project Management Project Duration Unit'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['pmproject']['duration'] = array(
    'title' => t('Duration'),
    'help' => t('Project Management Project Duration'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['pmproject']['manager_nid'] = array(
    'title' => t('Manager'),
    'help' => t('Project -> Manager'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Project -> Manager'),
    ),
  );

  $data['pmproject']['manager_title'] = array(
    'title' => t('Project manager'),
    'help' => t('Project Management Project Manager (title only)'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['pmproject']['assigned_nid'] = array(
    'title' => t('Assigned'),
    'help' => t('Project -> Assigned'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Project -> Assigned'),
    ),
  );

  $data['pmproject']['assigned_title'] = array(
    'title' => t('Assigned'),
    'help' => t('Project Management Project Assigned (title only)'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['pmproject']['operation'] = array(
    'field' => array(
      'title' => t('Edit/Delete link'),
      'help' => t('Provide a simple link to edit and delete the node.'),
      'handler' => 'pm_handler_field_operation',
      'type' => 'pmproject',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_handlers().
 */
function pmproject_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'pm'),
    ),
    'handlers' => array(
      'pm_handler_field_attributes_domain' => array(
        'parent' => 'views_handler_field',
      ),
      'pm_handler_filter_attributes_domain' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      'pm_handler_field_operation' => array(
        'parent' => 'views_handler_field_node_link',
        'path' => drupal_get_path('module', 'pm'),
      ),
    ),
  );
}
