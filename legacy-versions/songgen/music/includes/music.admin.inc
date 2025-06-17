<?php
/**
 * @file
 * Admin page callbacks for the Music module.
 *
 * @ingroup music
 */

/**
 * Form builder; Administer the music Module.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function music_admin_select_form($form, &$form_state) {

  // Create a parent element
  $form['music_admin'] = array(
    '#tree' => TRUE
  );

  // Create our cache duration options
  $duration_options = array(
    '+1 hour' => 'One hour',
    '+6 hours' => 'Six hours',
    '+12 hours' => 'Twelve hours',
    '+1 day' => 'One day',
    '+3 days' => 'Three days (recommended)',
    '+5 days' => 'Five days',
    '+2 weeks' => 'Two weeks',
    '+3 weeks' => 'Three weeks',
    '+1 month' => 'One month',
    '+3 months' => 'Three months',
    '+6 months' => 'Six months',
    '+9 months' => 'Nine months',
    '+1 year' => 'One year',
    '+5 years' => 'Five years'
  );

  // Display our cache duration dropdown
  $form['music_admin']['cache_duration'] = array(
    '#title' => 'Cache Duration',
    '#type' => 'select',
    '#options' => $duration_options,
    '#default_value' => variable_get('music_cache_duration', '+1 hour'),
  );

  // Create our debug status options
  $debug_options = array(
    TRUE => 'On',
    FALSE => 'Off'
  );

  // Display our debug status dropdown
  $form['music_admin']['music_debug'] = array(
    '#title' => 'Debug Mode',
    '#type' => 'select',
    '#options' => $debug_options,
    '#default_value' => variable_get('music_debug', FALSE),
  );

  // Define the submit callback
  $form['#submit'][] = 'music_admin_select_form_submit';

  // Return the form
  return system_settings_form($form);
}

/**
 *
 * Implements hook_submit().
 *
 * Front page management submission handler.
 */
function music_admin_select_form_submit($form, &$form_state) {

  // Set the cache duration to our submitted value
  variable_set('music_cache_duration', $form_state['values']['music_admin']['cache_duration']);

  // Set the debug status to our submitted value
  variable_set('music_debug', $form_state['values']['music_admin']['music_debug']);

}