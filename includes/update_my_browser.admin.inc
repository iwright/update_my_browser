<?php

/**
 * @file
 * Provides the admin form page for update my browser module.
 */

/**
 * Admin form for the update my browser configuration page.
 *
 * @param $form The initial empty form.
 * @param $form_state The current state of the form.
 * @return The form to be rendered out.
 */
function update_my_browser_form($form, &$form_state) {

  $form['umb_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configuaration Settings'),
  );

  // Active selection for recommended settings.
  $form['umb_browser_selection_recommended_type'] = array(
    '#type' => 'fieldset',
    '#title' => t('Active Selection'),
    '#tree' => TRUE,
    '#states' => array(
      'visible' => array(
        ':input[#umb_browser_option_selection]' => array('value' => 'recommended'),
      ),
    ),
    '#description' => t('Please see <a href="@updatemybrowser" title="updatemybrowser.org" target="_blank">updatemybrowser.org</a> for the default recommend browser versions.', array('@updatemybrowser' => 'http://updatemybrowser.org/widget')),
  );

  // Active selection for advance settings.
  $form['umb_browser_selection_advance_type'] = array(
    '#type' => 'fieldset',
    '#title' => t('Active Selection'),
    '#tree' => TRUE,
    '#states' => array(
      'visible' => array(
        ':input[#umb_browser_option_selection]' => array('value' => 'advance'),
      ),
    ),
    '#description' => t('Configure Update My Browser to meet your needs.'),
  );

  // Advance settings.
  $form['umb_advance_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advance Settings'),
  );

  // The browser options to display in our form.
  $umb_advance_settings = array(
    'umb_immediately_display' => t('Immediately display browser bar'),
    'umb_non_critical' => t('Display bar for non-critical updates'),
  );

  $form['umb_advance_settings']['umb_advance_settings'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Set how the notification reacts'),
    '#options' => $umb_advance_settings,
    '#default_value' => variable_get('umb_advance_settings', array('umb_immediately_display', 'umb_non_critical')),
  );

  // The browser options to display in our form.
  $umb_browser_options = array(
    'recommended' => t('Recommended'),
    'advance' => t('Advance'),
  );

  $form['umb_settings']['umb_browser_option_selection'] = array(
    '#type' => 'radios',
    '#title' => t('Minimum requirements:'),
    '#options' => $umb_browser_options,
    '#default_value' => variable_get('umb_browser_option_selection', 'recommended'),
  );

  return system_settings_form($form);
}
