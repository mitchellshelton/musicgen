<?php

  // Load the progression class
  include_once("progression.class");

  $key = array();
  $key['note'] = 'C';
  $key['quality'] = 'Major';
  $length = 4;
  // Get a progression
  $progression = new Progression($key, $length);

  $output = '';
  $output .= 'Key: ' . $progression->progression['properties']['key']['note'] . ' ' . $progression->progression['properties']['key']['quality'] . '<br />';
  $output .= 'Length: ' . $progression->progression['properties']['length'] . '<br /><br />';

  for ($i = 0; $i < count($progression->progression['progression']); $i++) {
    $current_step = $i + 1;
    $output .= '<strong>Step ' . $current_step . '</strong> <br />Chord:<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;' . $progression->progression['progression'][$i] . ' ( ' .
      $progression->progression['properties']['chords'][$i][0] . ' ' .
      $progression->progression['properties']['chords'][$i][1] . ' ' .
      $progression->progression['properties']['chords'][$i][2]
    . ')<br /><br />';
  }

  print $output;

  // Load the drums class
  include_once("drums.class");
  // Get the drum patterns
  $drum = new Drums();
  // Load the drum patterns object into a variable
  $drum_patterns = $drum->patterns;
  // Select a drum pattern
  $drum_pattern = $drum_patterns[0];

  print 'Drum Pattern';
  print '<pre>';
  print_r($drum_pattern);
  print '</pre>';

  // Load the bass class
  include_once("bass.class");
  // Get the bassline by passing in the chord progression and selected drum pattern
  $bass = new Bass($progression, $drum_pattern);
  // Load the bass line into a variable
  $bassline = $bass->bassline;

  print 'Bass Line';
  print '<pre>';
  print_r($bassline);
  print '</pre>';

  // Load the backing class
  include_once("backing.class");
  // Get the backing by passing in the chord progression and generated bassline pattern
  $backing = new Backing($progression, $bassline);
  // Load the backing into a variable
  $backing_pattern = $backing->pattern;

  print 'Backing';
  print '<pre>';
  print_r($backing_pattern);
  print '</pre>';

  // Load the melody class
  include_once("melody.class");
  // Get the melody by passing in the chord progression and generated bassline pattern
  $melody = new Melody($progression, $bassline);
  // Load the melody into a variable
  $melody_one = $melody->melody_one;
  $melody_two = $melody->melody_two;
  $melody_three = $melody->melody_three;

  print '<pre>';
  print 'Melody One';
  print '<pre>';
  print_r($melody_one);
  print '</pre>';

  print 'Melody Two';
  print '<pre>';
  print_r($melody_two);
  print '</pre>';

  print 'Melody Three';
  print '<pre>';
  print_r($melody_three);
  print '</pre>';

?>