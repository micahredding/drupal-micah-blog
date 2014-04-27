<?php

/**
 * @file
 * forward.tokens.inc
 * Provide tokens related to the forward module
 */

/**
 * Implements hook_token_info().
 */
function forward_token_info() {
  $data['types'] = array(
    'forward' => array(
      'name' => t('Forward'),
      'description' => t('Tokens related to forward module.'),
    ),
  );
  $data['tokens'] = array(
    'forward' => array(
      'recipients' => array(
        'name' => t("Email recipient(s)"),
        'description' => t("Recipient email address or email addresses for forwarded content."),
      ),
      'sender' => array(
        'name' => t("Sender's name"),
        'description' => t("Name of sender as entered in Forwarding form."),
      ),
      'entity-type' => array(
        'name' => t("Entity type"),
        'description' => t('The type of entity being forwarded, or "page" if no entity type is available.'),
      ),
    ),
  );
  return $data;
}

 /**
 * Returns the label of a bundle.
 *
 * @param $input_entity_type
 *   The entity type; e.g. 'node' or 'user'.
 * @param $input_bundle
 *   The machine name of the bundle for which we want the human-readable label.
 *
 * @return
 *   A string with the human-readable name of the bundle, or the machine readable name 
 *   if not specified.
 */
function forward_entity_bundle_label($input_entity_type, $input_bundle) {
  if (function_exists('entity_bundle_label')) {
    return entity_bundle_label($input_entity_type, $input_bundle);
  } else {
    $labels = &drupal_static(__FUNCTION__, array());

    if (empty($labels)) {
      foreach (entity_get_info() as $entity_type => $entity_info) {
        foreach ($entity_info['bundles'] as $bundle => $bundle_info) {
          $labels[$entity_type][$bundle] = !empty($bundle_info['label']) ? $bundle_info['label'] : $bundle;
        }
      }
    }
    return isset($labels[$input_entity_type][$input_bundle]) ? $labels[$input_entity_type][$input_bundle] : $input_bundle;
  }
}

/**
 * Implements hook_tokens().
 */
function forward_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  if (($type == 'forward') && !empty($data['forward'])) {
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'entity-type':
          if (isset($data['forward']['entity'])) {
            $entity = $data['forward']['entity'];
            list($id, $vid, $bundle) = entity_extract_ids($entity->type(), $entity->value());
            $entity_type = forward_entity_bundle_label($entity->type(), $bundle);
          }
          $replacements[$original] = isset($data['forward']['entity']) ? filter_xss($entity_type) : t('page');
          break;
        case 'recipients':
          $replacements[$original] = isset($data['forward']['recipients']) ? filter_xss(implode($data['forward']['recipients'], ', ')) : t('(Recipient list)');
          break;
        case 'sender':
          $replacements[$original] = isset($data['forward']['sender']) ? filter_xss($data['forward']['sender']) : t('(Your name)');
          break;
      }
    }
  }
  return $replacements;
}
