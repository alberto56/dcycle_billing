<?php
/**
 * @file
 * Functions to expose Project Management Timetracking data to Views.
 */
function pmtimetracking_views_data() {
  $data['pmtimetracking']['table']['group']  = 'Project Management Timetracking';
  $data['pmtimetracking']['table']['join'] = array(
    'node' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
  );

  $data['pmtimetracking']['organization_nid'] = array(
    'title' => t('Organization'),
    'help' => t('Timetracking -> Organization'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Timetracking -> Organization'),
    ),
  );

  $data['pmtimetracking']['organization_title'] = array(
    'title' => t('Organization'),
    'help' => t('Project Management Timetracking Organization (title only)'),
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

  $data['pmtimetracking']['project_nid'] = array(
    'title' => t('Project'),
    'help' => t('Timetracking -> Project'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Timetracking -> Project'),
    ),
  );

  $data['pmtimetracking']['project_title'] = array(
    'title' => t('Project'),
    'help' => t('Project Management Timetracking Project (title only)'),
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

  $data['pmtimetracking']['task_nid'] = array(
    'title' => t('Task'),
    'help' => t('Timetracking -> Task'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Timetracking -> Task'),
    ),
  );

  $data['pmtimetracking']['task_stepno'] = array(
    'title' => t('Task step number'),
    'help' => t('Project Management Timetracking Task Step Number'),
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

  $data['pmtimetracking']['task_title'] = array(
    'title' => t('Task'),
    'help' => t('Project Management Timetracking Task (title only)'),
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

  $data['pmtimetracking']['ticket_nid'] = array(
    'title' => t('Ticket'),
    'help' => t('Timetracking -> Ticket'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Timetracking -> Ticket'),
    ),
  );

  $data['pmtimetracking']['ticket_title'] = array(
    'title' => t('Ticket'),
    'help' => t('Project Management Timetracking Ticket (title only)'),
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

  $data['pmtimetracking']['duration'] = array(
    'title' => t('Duration'),
    'help' => t('Project Management Timetracking Duration'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['pmtimetracking']['billing_duration'] = array(
    'title' => t('Billing duration'),
    'help' => t('Project Management Timetracking Billing Duration'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['pmtimetracking']['billable'] = array(
    'title' => t('Billable'),
    'help' => t('Project Management Timetracking Billable'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['pmtimetracking']['billed'] = array(
    'title' => t('Billed'),
    'help' => t('Project Management Timetracking Billed'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['pmtimetracking']['operation'] = array(
    'field' => array(
      'title' => t('Edit/Delete link'),
      'help' => t('Provide a simple link to edit and delete the node.'),
      'handler' => 'pm_handler_field_operation',
      'type' => 'pmtimetracking',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_handlers().
 */
function pmtimetracking_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'pm'),
    ),
    'handlers' => array(
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
