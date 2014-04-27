<?php

/**
 * Implements hook_views_data().
 */
function forward_views_data() {

  // Forward link
  $entity_types = entity_get_info();
  foreach ($entity_types as $type => $info) {
    if (!empty($info['view modes'])) {
      $label = ($type == 'node') ? 'Content' : $info['label'];
      $data[$info['base table']]['forward'] = array(
        'field' => array(
          'group' => t($label),
          'title' => t('Forward link'),
          'help' => t('Provide a simple link to forward the ' . strtolower($label) . ' to a friend.'),
          'handler' => 'forward_handler_field_forward_link',
          'click sortable' => FALSE,
        ),
      );
      if ($type == 'node') {
        // Place a second copy in the Forward group for user convenience
        $data[$info['base table']]['forward_forward'] = array(
          'field' => array(
            'group' => t('Forward'),
            'title' => t('Forward link'),
            'help' => t('Provide a simple link to forward the content to a friend.'),
            'handler' => 'forward_handler_field_forward_link',
            'click sortable' => FALSE,
          ),
        );
      }
    }
  }

  // Forward statistics

  // Define the base group of this table. Fields that don't
  // have a group defined will go into this field by default.
  $data['forward_statistics']['table'] = array(
    'group' => t('Forward'),
  );

  // For other entity base tables, explain how we join.
  $entity_types = entity_get_info();
  foreach ($entity_types as $type => $info) {
    if (!empty($info['view modes'])) {
      $data['forward_statistics']['table']['join'][$info['base table']] = array(
        // 'left_field' is the primary key in the referenced table.
        // 'field' is the foreign key in this table.  
        'left_field' => $info['entity keys']['id'],
        'field' => 'id',
        'extra' => array(
          array('field' => 'type', 'value' => $type),
        ),
      );
    }
  }

  // Forward statistics fields.
  $data['forward_statistics']['forward_count'] = array(
    'title' => t('Forward count'),
    'help' => t('The number of times an entity was forwarded.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['forward_statistics']['clickthrough_count'] = array(
    'title' => t('Clickthrough count'),
    'help' => t('The number of times an entity in a forward email was clicked on.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['forward_statistics']['last_forward_timestamp'] = array(
    'title' => t('Most recent forward'),
    'help' => t('The last time that an entity was forwarded.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_timestamp',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );

  // Forward log.
  $data['forward_log']['table'] = array(
    'group' => t('Forward'),
    'base' => array(
      'field' => 'uid',
      'title' => t('Forward Log'),
      'weight' => -10,
    ),
  );

  // Forward log fields.
  $data['forward_log']['path'] = array(
    'title' => t('Forwarded Path'),
    'help' => t('The path that was forwarded.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['forward_log']['type'] = array(
    'title' => t('Type'),
    'help' => t('Type.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['forward_log']['timestamp'] = array(
    'title' => t('Timestamp'),
    'help' => t('The date and time at which the path was forwarded.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
  $data['forward_log']['uid'] = array(
    'title' => t('Uid'),
    // The help that appears on the UI,
    'help' => t('The user ID of the user that forwarded a path.'),
    'field' => array(
      'handler' => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
      // display this field in the summary
      'name field' => 'name',
    ),
    'relationship' => array(
      'base' => 'users',
      'field' => 'uid',
      'label' => 'User',
      'help' => t('Bring in data about the user.'),
    ),
    'filter' => array(
      'title' => t('Name'),
      'handler' => 'views_handler_filter_user_name',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['forward_log']['hostname'] = array(
    'title' => t('Hostname'),
    'help' => t('Hostname of the user that forwarded a path.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}

