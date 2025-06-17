<?php
/**
 * @file
 * Music generator
 *
 * @ingroup music
 */

/**
 * Generate a song
 */
function music_generator() {

  // Initialize the output variable
  $output = '';

  if (isset($_GET['multi'])) {

    // Grab the multi input count from the URL
    $multi = $_GET['multi'];

    // Run the multiple progression generator
    $output = music_multi_generator($multi);

    // Return the multi output
    return $output;
    // Exit the method
    exit;
  }

  $output .= 'Generator Page';

  if (isset($_GET['key']) && isset($_GET['length'])) {
    $key = $_GET['key'];
    $length = $_GET['length'];
  }
  else {
    $key = '';
    $length = '';
  }

  // Get a random progression
  $song_progression = music_get_song_progression($key, $length);

  // Display the progression
  $output .= "<hr />";

  $output .= 'Key: ' . $song_progression['properties']['key'] . '<br />';
  $output .= 'Length: ' . $song_progression['properties']['length'] . '<br /><br />';

  // Initialize an array to hold all of our bass lines
  $bass_lines = array();

  for ($i = 0; $i < count($song_progression['progression']); $i++) {
    $current_step = $i + 1;
    $output .= '<strong>Step ' . $current_step . '</strong> <br />Chord:<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;' . $song_progression['progression'][$i] . ' ( ' .
      $song_progression['properties']['chords'][$i][0] . ' ' .
      $song_progression['properties']['chords'][$i][1] . ' ' .
      $song_progression['properties']['chords'][$i][2]
    . ')<br /><br />';

    $chord = $song_progression['properties']['chords'][$i];
    $bassline = music_bass_line_builder($chord);
    $bass_lines[] = $bassline;
    $output .= 'Bassline: <br />';

    for ($j = 0; $j < count($bassline['note']); $j++) {
      $output .= '&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;' . $bassline['length'][$j] . ' ' . $bassline['note'][$j] . '<br />';
    }

    $output .= '<br />';
  }

  $output .= 'Melodies: <br />';
  $melodies = music_melody_builder($song_progression['properties']['key']);

  $output .= 'Melody 1: <br />';
  for ($i = 0; $i < count($melodies[0]); $i++) {
    $output .= $melodies[0][$i] . ' ';
  }
  $output .= '<br />';

  $output .= 'Melody 2: <br />';
  for ($i = 0; $i < count($melodies[1]); $i++) {
    $output .= $melodies[1][$i] . ' ';
  }
  $output .= '<br />';

  $output .= 'Melody 3: <br />';
  for ($i = 0; $i < count($melodies[2]); $i++) {
    $output .= $melodies[2][$i] . ' ';
  }

  $output .= "<hr />";


  // Load the song class
  include_once("music.song.class");
  $song = new Song($song_progression, $bass_lines, $melodies);
  $complete_song = $song->song_builder();

  $output .= "<br /><strong>Song</strong><hr />";
  $output .= $complete_song;
  print '<pre>';
  print_r($song->xml_file);
  print '</pre>';
  $output .= "<hr />";



  // return the output
  return $output;
}

/**
 * Generate Multiple Progressions
 */
function music_multi_generator($multi) {

  // Initialize the output variable
  $output = '';

  $output .= 'Multiple Progression Generator<br />';

  if (isset($_GET['key']) && isset($_GET['length'])) {
    $key = $_GET['key'];
    $length = $_GET['length'];
  }
  else {
    $key = '';
    $length = '';
  }

  // Loop over the given number of progressions
  for($j = 0; $j < $multi; $j++) {

    // Get a random progression
    $song_progression = music_get_song_progression($key, $length);
    // Output the current progression number
    $output .= '<br />';

    for ($i = 0; $i < count($song_progression['progression']); $i++) {
      $current_step = $i + 1;
      $output .= '' .
        $song_progression['properties']['chords'][$i][0] . ' ' .
        $song_progression['properties']['chords'][$i][1] . ' ' .
        $song_progression['properties']['chords'][$i][2]
        . '';
      $output .= '<br />';
    }

  }

  return $output;
}

function music_get_song_progression($key = '0', $length = '0') {

  // Random values need to be generated
  if ($key == 0 && $length == 0) {
    // Get a random key
    $key = music_random_key();

    // Get the length of the progression sequence
    $progression_length = array(4, 8, 12);

    // Load the dice class
    include_once("music.dice.class");
    $dice = new Dice();

    // Get a random length
    $length = $progression_length[$dice->roll(1, 3) - 1];
  }

  // Get the progression sequence
  $progression_steps = music_progression_steps($length);

  // Get the progression
  $progression = music_working_progression($length, $key, $progression_steps);

  // Get the song chords
  $progression_chords = music_progression_chords($progression_steps, $key, $progression);

  // Initialize our return array
  $song_progression = array();

  // Get our working progression notes
  $song_progression['progression'] = $progression;
  $song_progression['properties'] = array('key' => $key, 'length' => $length, 'chords' => $progression_chords);

  // Return the song progression
  return $song_progression;
}

function music_progression_chords($progression_steps, $key, $progression) {

  // Load the music theory class
  include_once("music.musictheory.class");
  $theory = new Musictheory();

  // Get the progression pattern and chord table builder
  $chord_progression_pattern = $theory->chord_progression_pattern;
  $chord_tables = $theory->chord_tables;

  // Split the key and quality
  $key_parts = explode(' ', $key);
  $key_only = $key_parts[0];
  $quality_only = $key_parts[1];

  // Initialize our chord array
  $progression_chords = array();

  // Loop over the progression
  for ($i = 0; $i < count($progression_steps); $i++) {

    // Get the pattern letter (this will be upper and lower case roman numerals or an *)
    $pattern = $chord_progression_pattern[$quality_only][$progression_steps[$i] - 1];

    // Get major chord
    if (ctype_upper($pattern) === true) {
      // If the pattern is upper case, we grab the Major chord for this step
      $progression_chords[] = array(
        // Root
        $chord_tables['Major'][$progression[$i]][0],
        // Major Third
        $chord_tables['Major'][$progression[$i]][1],
        // Perfect Fifth
        $chord_tables['Major'][$progression[$i]][2]
      );
    }
    // Get minor chord
    else if (ctype_lower($pattern) === true) {
      // If the pattern is lower case, we grab the Minor chord for this step
      $progression_chords[] = array(
        // Root
        $chord_tables['Minor'][$progression[$i]][0],
        // Minor Third
        $chord_tables['Minor'][$progression[$i]][1],
        // Perfect Fifth
        $chord_tables['Minor'][$progression[$i]][2]
      );
    }
    // Get diminished chord
    if (strstr($pattern, '*') == '*') {
      // If the pattern is contains an '*', we grab the Diminished chord for this step
      $progression_chords[] = array(
        // Root
        $chord_tables['Diminished'][$progression[$i]][0],
        // Third
        $chord_tables['Diminished'][$progression[$i]][1],
        // Fifth
        $chord_tables['Diminished'][$progression[$i]][2]
      );
    }
  }

  // Return the array of chords
  return $progression_chords;
}

function music_working_progression($length, $key, $progression_steps) {

  // Load the music theory class
  include_once("music.musictheory.class");
  $theory = new Musictheory();
  // Get the scales
  $scales = $theory->scales;

  // Split the key and quality
  $key_parts = explode(' ', $key);
  $key_only = $key_parts[0];
  $quality_only = $key_parts[1];

  // Initialize our return array
  $working_progression = array();
  // Loop over our steps
  for ($i = 0; $i < $length; $i++) {
    // Get each step from the scales in the progression
    $working_progression[] = $scales[$quality_only][$key_only][$progression_steps[$i] - 1];
  }

  // Return our working progression
  return $working_progression;
}

function music_random_key() {
  // Load the music theory class
  include_once("music.musictheory.class");
  $theory = new Musictheory();

  // Load the qualities and scales into an array
  $song_scale = $theory->song_scale;

  // Load the dice class
  include_once("music.dice.class");
  $dice = new Dice();

  // Roll for quality
  $quality_roll = $dice->roll(1, 2) - 1;

  // Get the quality
  $quality = $song_scale[$quality_roll][0];

  // Get the number of notes from our selected quality
  $num_notes = count($song_scale[$quality_roll][1]);

  // Roll for notes
  $note_roll = $dice->roll(1, $num_notes) - 1;

  // Get the note
  $note = $song_scale[$quality_roll][1][$note_roll];

  // Merge the quality and note for the key
  $key = t('@note @quality', array('@note' => $note, '@quality' => $quality));

  // Return the random key
  return $key;
}

function music_progression_steps($length = 4, $is_alternative = FALSE) {

  // Load the dice class
  include_once("music.dice.class");
  $dice = new Dice();

  /*
   * These are tonal steps for generating a "pleasing" pattern.
   * The 1 represents the first note in the pattern with the numbers
   * in the corresponding array representing the position of the next note.
   * This can be used both for chord progressions and melody generation.
   */
  $steps = array(
    1 => array(1, 2, 3, 4, 5, 6, 7),
    2 => array(4, 5, 7),
    3 => array(2, 4, 6),
    4 => array(1, 3, 5, 7),
    5 => array(1),
    6 => array(2, 4, 5, 1),
    7 => array(1, 3)
  );

  // An alternative chord following pattern
  $steps_alternative = array(
    1 => array(6, 2, 4, 5),
    2 => array(1, 4, 3),
    3 => array(5, 4, 2),
    4 => array(2, 5, 1, 3),
    5 => array(3, 6, 4, 1),
    6 => array(1, 7, 5),
    7 => array(6)
  );

  // Initialize the progression array
  $progression = array();
  // Generate the first note
  $first_note = $dice->roll(1, 7);

  // Record the first step as the first note
  $progression[] = $first_note;
  // Initialize and record our last step
  $last_step = $first_note;

  // Populate the progression
  /*
   * This section needs more work, need a "center" note that we work toward from both ends
   */
  for ($i = 1; $i < $length - 1; $i++) {
    // Determine which step jumps us back to a single note
    if ($is_alternative == TRUE) {
      $jump_step = 7;
      $to_step = 6;
    }
    else {
      $jump_step = 5;
      $to_step = 1;
    }
    // Determine if we are on a jump step, if not, record a random roll from those available
    if ($last_step != $jump_step) {
      $current_step = $steps[$last_step][$dice->roll(1, count($steps[$last_step])) - 1];
    }
    else {
      $current_step = $to_step;
    }
    // Add the step to the progression array
    $progression[] = $current_step;
    // Store the last step for the next pass
    $last_step = $current_step;
  }
  // Close the progression with the first note
  $progression[] = $first_note;

  // Return the progression
  return $progression;
}

function music_bass_line_builder($chord) {

  // Load the dice class
  include_once("music.dice.class");
  $dice = new Dice();

  // Initialize the bass line
  $bass_line = array();
  // Define the available notes
  $note = array(
    $chord[0] . ', ' . $chord[2],
    $chord[0] . ', ' . $chord[1],
    $chord[0],
    $chord[1],
    $chord[2]
  );
  // Define the available lengths
  $length = array('short', 'long');
  // Initialize the number of steps
  $step_count = 4;
  $last_note = '';
  $last_length = '';

  // Loop over the steps
  for ($i = 0; $i < $step_count; $i++) {
    // Get a random note
    $this_note = $note[$dice->roll(1, count($note)) - 1];

    // Only get a random length if this is the first or third note
    if ($i == 0 || $i == 2) {
      // Get a random length
      $this_length = $length[$dice->roll(1, count($length)) - 1];
    }
    else {
      // If this is the second or fourth note, it must be a short note
      $this_length = $length[0];
    }

    // If the last length was long and the note selected was also the same
    if ($last_length == 'long' && $last_note == $this_note) {
      // Select the new random note, make sure it is not the same as the last note
      while ($last_note == $this_note) {
        $this_note = $note[$dice->roll(1, count($note)) - 1];
      }
    }

    // Assign the selected note
    $bass_line['note'][] = $this_note;

    // If it is a short note
    if ($this_length == $length[0]) {
      // Assign the length
      $bass_line['length'][] = '1/4 note';
    }
    else {
      // Assign the length
      $bass_line['length'][] = '1/2 note';
      // If it is a long note we skip a step
      $i++;
    }
    // Store the last note and length to assist with preventing repetition
    $last_note = $this_note;
    $last_length = $this_length;
  }

  // Return the completed bassline
  return $bass_line;
}

function music_melody_builder($key) {
  // Load the music theory class
  include_once("music.musictheory.class");
  $theory = new Musictheory();

  // Load the qualities and scales into an array
  $song_scale = $theory->scales;

  // Break apart the given key
  $key_parts = explode(' ', $key);
  $note = $key_parts[0];
  $quality = $key_parts[1];
  // Grab the scale
  $scale = $song_scale[$quality][$note];

  // Initialize the melodies
  $melody01 = array();
  $melody02 = array();
  $melody03 = array();

  // Build a melody progression
  $m1 = music_progression_steps(8);
  // Loop over the progression
  for ($i = 0; $i < count($m1); $i++) {
    // Place the note into the melody array
    $melody01[] = $scale[$m1[$i] - 1];
  }

  // Build a melody progression
  $m2 = music_progression_steps(12);
  // Loop over the progression
  for ($i = 0; $i < count($m2); $i++) {
    // Place the note into the melody array
    $melody02[] = $scale[$m2[$i] - 1];
  }

  // Build a melody progression
  $m3 = music_progression_steps(8);
  // Loop over the progression
  for ($i = 0; $i < count($m3); $i++) {
    // Place the note into the melody array
    $melody03[] = $scale[$m3[$i] - 1];
  }

  // Copy all of the melodies into a single array
  $melody = array($melody01, $melody02, $melody03);

  // Return all three melodies
  return $melody;
}