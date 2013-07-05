<?php

/**
 * Admin settings form
 */
function anonymous_login_admin_settings($form, &$form_state) {
  $form['anonymous_login_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Page paths'),
    '#default_value' => variable_get('anonymous_login_paths', NULL),
    '#description' => t('Enter a list of page paths that will force anonymous users to login before viewing. After logging in, they will be redirected back to the requested page. Enter each path on a different line. Wildcards (*) can be used.'),
  );
  
  return system_settings_form($form);
}
