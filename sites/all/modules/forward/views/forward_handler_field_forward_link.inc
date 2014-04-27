<?php

/**
 * @file
 * Definition of forward_handler_field_forward_link.
 */

/**
 * Field handler to present a "forward this node" link
 *
 * @ingroup views_field_handlers
 */
class forward_handler_field_forward_link extends views_handler_field_entity {
  function construct() {
    parent::construct();
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Prevent rewrite
    $form['alter']['#access'] = FALSE;
  }

  function render($values) {
    $content = '';
    if (user_access('access forward')) {
      $entity = entity_load_single($this->entity_type, $values->{$this->field_alias});
      if ($entity) {
        list($id, $vid, $bundle) = entity_extract_ids($this->entity_type, $entity);
      }

      if ($entity && variable_get('forward_entity_' . $this->entity_type, FALSE) && variable_get('forward_'.$this->entity_type.'_'.$bundle, FALSE)) {
        $content = theme('forward_link', array('entity_type' => $this->entity_type, 'entity' => $entity));
      }
    }
    return $content;
  }
}
