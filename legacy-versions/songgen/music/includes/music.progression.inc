<?php
/**
 * @file
 * Forms to Build a Chord Progression.
 *
 * @ingroup music
 */

/**
 * Form builder; Build a Chord Progression.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function music_progression_form($form, &$form_state) {

  // Load the music theory class
  include_once("music.musictheory.class");
  $theory = new Musictheory();

  // Load the qualities and scales into an array
  $song_scale = $theory->song_scale;

  // Create a parent element and use our custom theme
  $form['progression_form']['progession_selection'] = array(
    '#prefix' => '<div id="progression-form">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
    '#theme' => 'music_theme_name'
  );

  // Get the list of options to populate the quality dropdown.
  $music_progression_quality_options = _music_progression_quality_options($song_scale);

  // If we have a value for the first dropdown from $form_state['values'] we use
  // this both as the default value for the first dropdown and also as a
  // parameter to pass to the function that retrieves the options for the
  // second dropdown.
  $selected = isset($form_state['values']['progression_quality']) ? $form_state['values']['progression_quality'] : key($music_progression_quality_options);

  // Display our quality dropdown
  $form['progression_form']['progression_quality'] = array(
    '#title' => 'Quality',
    '#description' => t('Select a Quality for your scale.'),
    '#type' => 'select',
    '#options' => $music_progression_quality_options,
    '#weight' => 0,
    '#default_value' => $selected,

    // Bind an ajax callback to the change event (which is the default for the
    // select form type) of the first dropdown. It will replace the second
    // dropdown when rebuilt
    '#ajax' => array(
        // When 'event' occurs, Drupal will perform an ajax request in the
        // background. Usually the default value is sufficient (change for
        // select elements), but valid values include any jQuery event,
        // most notably 'mousedown', 'blur', and 'submit'.
        //'event' => 'change',
        'callback' => 'music_progression_key_ajax_callback',
        'wrapper' => 'dropdown-progression-key-replace',
    ),

  );

  // Display our key dropdown
  $form['progression_form']['progression_key'] = array(
    '#title' => 'Key',
    '#description' => t('Select a @quality for your scale.', array('@quality' => $music_progression_quality_options[$selected])),
    '#type' => 'select',
    '#options' => _music_progression_key_options($selected, $song_scale),
    '#prefix' => '<div id="dropdown-progression-key-replace">',
    '#suffix' => '</div>',
    '#weight' => 1,
    '#default_value' => isset($form_state['values']['progression_key']) ? $form_state['values']['progression_key'] : '',
  );

  // Randomize the selections
  $form['progression_form']['progression_length'] = array(
    '#title' => 'Progression Length',
    '#description' => 'Select a progression length.',
    '#type' => 'select',
    '#options' => array(4, 8, 12),
    '#default_value' => 4,
    '#weight' => 2,
  );

  // Randomize the selections
  $form['progression_form']['progression_random'] = array(
    '#title' => 'Randomize',
    '#default_value' => 'Random',
    '#description' => 'Randomize the selections.',
    '#type' => 'submit',
    '#weight' => 3,
  );

  // Define the submit callback
  $form['#submit'][] = 'music_progression_form_submit';

  // Return the form
  return system_settings_form($form);
}

/**
 * Selects just the second dropdown to be returned for re-rendering
 *
 * Since the controlling logic for populating the form is in the form builder
 * function, all we do here is select the element and return it to be updated.
 *
 * @return renderable array (the second dropdown)
 */
function music_progression_key_ajax_callback($form, $form_state) {
    return $form['progression_form']['progression_key'];
}

/**
 * Helper function to populate the quality dropdown.
 *
 * @return array of options
 */
function _music_progression_quality_options($song_scale) {

  // Initialize our options array
  $music_progression_quality_options = array();
  // Populate the options array
  foreach ($song_scale as $quality) {
    $music_progression_quality_options[] = $quality[0];
  }

  return $music_progression_quality_options;
}

/**
 * Helper function to populate the second dropdown. This would normally be
 * pulling data from the database.
 *
 * @param key. This will determine which set of options is returned.
 *
 * @return array of options
 */
function _music_progression_key_options($key = '', $song_scale) {

  // Initialize our options array
  $music_progression_key_options = array();
  // Populate the options array
  foreach ($song_scale[0][1] as $notes) {
    $music_progression_major_key_options[] = $notes;
  }
  // Populate the options array
  foreach ($song_scale[1][1] as $notes) {
    $music_progression_minor_key_options[] = $notes;
  }
  $options = array(
    0 => $music_progression_major_key_options,
    1 => $music_progression_minor_key_options
  );

  if (isset($options[$key])) {
      return $options[$key];
  }
  else {
      return array();
  }
}

/**
 *
 * Implements hook_submit().
 *
 * progression selection submission handler.
 */
function music_progression_form_submit($form, &$form_state) {

  if ($form_state['triggering_element']['#value'] == 'Random') {
    drupal_set_message(t('Random was submitted'), 'status');
    // Redirect to the generator page
    drupal_goto('music/generator');
  }
  else {
    // Set the debug status to our submitted value
    $progression_quality = $form['progression_form']['progression_quality']['#options'][$form_state['values']['progression_quality']];
    $progression_key = $form['progression_form']['progression_key']['#options'][$form_state['values']['progression_key']];
    $progression_length = $form['progression_form']['progression_length']['#options'][$form_state['values']['progression_length']];
    drupal_set_message(t('@key @quality was submitted at a length of @length steps', array('@key' => $progression_key, '@quality' => $progression_quality, '@length' => $progression_length)), 'status');
    // Redirect to the generator page
    drupal_goto(
      'music/generator',
      array('query' => array(
        'key' => $progression_key . ' ' . $progression_quality,
        'length' => $progression_length
      ))
    );
  }
}