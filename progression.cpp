#include "progression.h"
#include "music_theory.h"
#include "dice.h"
#include <unordered_map>

std::vector<Chord> chord_table_builder(const ScaleData& scales);

// Constructor
Progression::Progression(Key key, int length) {
    this->progression_result = this->music_get_song_progression(key, length);
}

// Generate song progression
SongProgression Progression::music_get_song_progression(Key key, int length) {
    Dice dice;
    MusicTheory theory;

    if (key.quality.empty() || key.note.empty()) {
        key = this->music_random_key();
    }

    if (length == 0) {
        std::vector<int> progression_length = {4, 8, 12};
        length = progression_length[dice.roll(1, 3) - 1];
    }

    auto progression_steps = this->music_progression_steps(length);
    auto progression = this->music_working_progression(length, key, progression_steps);
    auto progression_chords = this->music_progression_chords(progression_steps, key, progression);

    SongProgression song_progression;
    song_progression.progression = progression;
    song_progression.properties.key = key;
    song_progression.properties.length = length;
    song_progression.properties.chords = progression_chords;

    return song_progression;
}

// Random key generator
Key Progression::music_random_key() {
    MusicTheory theory;
    Dice dice;

    auto song_scale = theory.getSongScale();

    int quality_roll = dice.roll(1, 2) - 1;
    std::string quality = song_scale[quality_roll].first;

    int num_notes = song_scale[quality_roll].second.size();
    int note_roll = dice.roll(1, num_notes) - 1;
    std::string note = song_scale[quality_roll].second[note_roll];

    return {note, quality };
}

// Generate progression steps
std::vector<int> Progression::music_progression_steps(int length, bool is_alternative) {
    Dice dice;

    std::unordered_map<int, std::vector<int>> steps = {
        {1, {1, 2, 3, 4, 5, 6, 7}},
        {2, {4, 5, 7}},
        {3, {2, 4, 6}},
        {4, {1, 3, 5, 7}},
        {5, {1}},
        {6, {2, 4, 5, 1}},
        {7, {1, 3}}
    };

    std::unordered_map<int, std::vector<int>> steps_alternative = {
        {1, {6, 2, 4, 5}},
        {2, {1, 4, 3}},
        {3, {5, 4, 2}},
        {4, {2, 5, 1, 3}},
        {5, {3, 6, 4, 1}},
        {6, {1, 7, 5}},
        {7, {6}}
    };

    const auto& selected_steps = is_alternative ? steps_alternative : steps;

    std::vector<int> progression;
    int first_note = dice.roll(1, 7);
    progression.push_back(first_note);
    int last_step = first_note;

    for (int i = 1; i < length - 1; ++i) {
        int jump_step = is_alternative ? 7 : 5;
        int to_step = is_alternative ? 6 : 1;
        int current_step;

        if (last_step != jump_step) {
            const auto& possible_steps = selected_steps.at(last_step);
            int step_index = dice.roll(1, static_cast<int>(possible_steps.size())) - 1;
            current_step = possible_steps[step_index];
        } else {
            current_step = to_step;
        }

        progression.push_back(current_step);
        last_step = current_step;
    }

    progression.push_back(first_note);
    return progression;
}

// Generate working progression
std::vector<std::string> Progression::music_working_progression(int length, const Key& key, const std::vector<int>& progression_steps) {
    MusicTheory theory;
    auto scales = theory.getScales();

    std::vector<std::string> working_progression;

    const auto& mode_map = scales.at(key.quality);
    const auto& note_vector = mode_map.at(key.note);

    for (int i = 0; i < length; ++i) {
        int idx = progression_steps[i] - 1;
        working_progression.push_back(note_vector[idx]);
    }

    return working_progression;
}

// Generate progression chords
std::vector<std::vector<std::string>> Progression::music_progression_chords(const std::vector<int>& progression_steps, const Key& key, const std::vector<std::string>& progression) {
    MusicTheory theory;

    std::vector<std::string> chord_progression_pattern;
    for (const auto& [mode, pattern] : theory.getChordPatterns()) {
        if (mode == key.quality) {
            chord_progression_pattern = pattern;
            break;
        }
    }
    auto chord_tables = chord_table_builder(theory.getScales());

    std::vector<std::vector<std::string>> progression_chords;

    for (size_t i = 0; i < progression_steps.size(); ++i) {
        std::string pattern = chord_progression_pattern[progression_steps[i] - 1];
        std::vector<std::string> chord;

        for (const auto& c : chord_tables) {
            if (c.mode == key.quality && c.root == progression[i]) {
                chord = c.notes;
                break;
            }
        }
        progression_chords.push_back(chord);
    }

    return progression_chords;
}
