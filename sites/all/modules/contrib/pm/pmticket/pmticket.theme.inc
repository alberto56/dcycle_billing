<?php
/**
 * @file
 * Theme functions for PM Ticket.
 */

/**
 * Provides HTML markup for a pmticket node view.
 */
function theme_pmticket_view($variables) {
  $node = $variables['node'];

  $node->content['group1'] = array(
    '#prefix' => '<div class="field">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group1') : -20,
  );

  $node->content['group1']['organization'] = array(
    '#prefix' => '<div class="organization">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Organization'), 'value' => l($node->organization_title, 'node/' . $node->organization_nid))),
    '#weight' => 1,
  );

  $node->content['group1']['project_nid'] = array(
    '#prefix' => '<div class="project">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Project'), 'value' => l($node->project_title, 'node/' . $node->project_nid))),
    '#weight' => 2,
  );

  $node->content['group1']['task_nid'] = array(
    '#prefix' => '<div class="task">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Task'), 'value' => l($node->task_title, 'node/' . $node->task_nid))),
    '#weight' => 2,
  );

  $node->content['group2'] = array(
    '#prefix' => '<div class="field">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group2') : -19,
  );

  $node->content['group2']['category'] = array(
    '#prefix' => '<div class="category">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Category'), 'value' => check_plain(pm_attribute_value('Ticket category', $node->ticketcategory)))),
    '#weight' => 1,
  );

  $node->content['group2']['status'] = array(
    '#prefix' => '<div class="pm_status">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Status'), 'value' => check_plain(pm_attribute_value('Ticket status', $node->ticketstatus)))),
    '#weight' => 2,
  );

  $node->content['group2']['priority'] = array(
    '#prefix' => '<div class="priority">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Priority'), 'value' => check_plain(pm_attribute_value('Ticket priority', $node->ticketpriority)))),
    '#weight' => 3,
  );

  $node->content['group5'] = array(
    '#prefix' => '<div class="field">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group2') : -16,
  );

  $node->content['group5']['assigned'] = array(
    '#prefix' => '<div class="assigned">',
    '#suffix' => '</div>',
    '#markup' => theme('pm_view_item', array('label' => t('Assigned to'), 'value' => l($node->assigned_title, 'node/' . $node->assigned_nid))),
  );

  $body = field_get_items('node', $node, 'body');
  if ($body) {
    $node->content['body'] = array(
      '#prefix' => '<div class="pmbody">',
      '#suffix' => '</div>',
      '#markup' => theme('pm_view_item', array('label' => t('Description'), 'value' => $body[0]['safe_value'])),
      '#weight' => -15,
    );
  }

  return $node;
}
