<?php
/**
 * @file
 * Navigation for music module
 *
 * @ingroup music
 */

/**
 * Build the navigation block
 */
function music_navigation() {
  // Initialize the output variable
  $output = "";

  $output .= "<hr />";
  $output .= '<ul>';
  $output .= '<li>' . l(t('Progression'), 'music/progression') . '</li>';
  $output .= '<li>' . l(t('Generator'), 'music/generator') . '</li>';
  $output .= '</ul>';
  $output .= "<hr />";

  // Return the generator
  return $output;
}