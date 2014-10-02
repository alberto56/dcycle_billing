<?php
/**
 * @file
 * Functions to expose Project Management Ticket data to the Views module.
 */

/**
 * Implements hook_views_data().
 */
function pmticket_views_data() {
  $data['pmticket']['table']['group']  = 'Project Management Ticket';
  $data['pmticket']['table']['join'] = array(
    'node' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
  );

  $data['pmticket']['organization_nid'] = array(
    'title' => t('Organization'),
    'help' => t('Ticket -> Organization'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Ticket -> Organization'),
    ),
  );

  $data['pmticket']['organization_title'] = array(
    'title' => t('Organization'),
    'help' => t('Project Management Ticket Organization (title only)'),
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

  $data['pmticket']['project_nid'] = array(
    'title' => t('Project'),
    'help' => t('Ticket -> Project'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Ticket -> Project'),
    ),
  );

  $data['pmticket']['project_title'] = array(
    'title' => t('Project'),
    'help' => t('Project Management Ticket Project (title only)'),
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

  $data['pmticket']['task_nid'] = array(
    'title' => t('Task'),
    'help' => t('Ticket -> Task'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Ticket -> Task'),
    ),
  );

  $data['pmticket']['ticketcategory'] = array(
    'title' => t('Category'),
    'help' => t('Project Management Ticket category'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'pm_handler_field_attributes_domain',
      'domain' => 'Ticket Category',
      'icon' => 'category',
    ),
    'filter' => array(
      'handler' => 'pm_handler_filter_attributes_domain',
      'domain' => 'Ticket Category',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['pmticket']['ticketstatus'] = array(
    'title' => t('Status'),
    'help' => t('Project Management Ticket Status'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'pm_handler_field_attributes_domain',
      'domain' => 'Ticket Status',
      'icon' => 'status',
    ),
    'filter' => array(
      'handler' => 'pm_handler_filter_attributes_domain',
      'domain' => 'Ticket Status',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['pmticket']['ticketpriority'] = array(
    'title' => t('Priority'),
    'help' => t('Project Management Ticket priority'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'pm_handler_field_attributes_domain',
      'domain' => 'Ticket Priority',
      'icon' => 'priority',
    ),
    'filter' => array(
      'handler' => 'pm_handler_filter_attributes_domain',
      'domain' => 'Ticket Priority',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['pmticket']['task_title'] = array(
    'title' => t('Task'),
    'help' => t('Project Management Ticket Task (title only)'),
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

  $data['pmticket']['durationunit'] = array(
    'title' => t('Duration unit'),
    'help' => t('Project Management Ticket duration unit'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'pm_handler_field_attributes_domain',
      'domain' => 'Duration unit',
    ),
    'filter' => array(
      'handler' => 'pm_handler_filter_attributes_domain',
      'domain' => 'Duration unit',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['pmticket']['duration'] = array(
    'title' => t('Duration'),
    'help' => t('Project Management Ticket duration'),
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

  $data['pmticket']['assigned_nid'] = array(
    'title' => t('Assigned'),
    'help' => t('Ticket -> Assigned'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Ticket -> Assigned'),
    ),
  );

  $data['pmticket']['assigned_title'] = array(
    'title' => t('Assigned'),
    'help' => t('Project Management Ticket Assigned (title only)'),
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

  $data['pmticket']['operation'] = array(
    'field' => array(
      'title' => t('Edit/Delete link'),
      'help' => t('Provide a simple link to edit and delete the node.'),
      'handler' => 'pm_handler_field_operation',
      'type' => 'pmticket',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_handlers().
 */
function pmticket_views_handlers() {
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
