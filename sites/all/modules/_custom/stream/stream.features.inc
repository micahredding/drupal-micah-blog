<?php
/**
 * @file
 * stream.features.inc
 */

/**
 * Implements hook_views_api().
 */
function stream_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function stream_node_info() {
  $items = array(
    'stream' => array(
      'name' => t('Stream'),
      'base' => 'node_content',
      'description' => t('A short thought, status, or link'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
