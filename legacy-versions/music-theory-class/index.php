<?php

include_once("musictheory.class");

$theory = new Musictheory();
$song_scale = $theory->song_scale;
$scales = $theory->scales;
$chord_progression_pattern = $theory->chord_progression_pattern;
$chord_tables = $theory->chord_tables;
$theoretical_notes = $theory->theoretical_notes;

print "<pre>";
print 'Song Scale:';
print_r($song_scale);
print 'Scales:';
print_r($scales);
print 'Chord Progression Pattern:';
print_r($chord_progression_pattern);
print 'Chord Tables:';
print_r($chord_tables);
print 'Theoretical Notes:';
print_r($theoretical_notes);
print "</pre>";

?>