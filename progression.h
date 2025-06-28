#ifndef PROGRESSION_H
#define PROGRESSION_H

#include <string>
#include <vector>

struct Key {
  std::string note;
  std::string quality;
};

struct SongProgression {
  std::vector<std::string> progression;
  struct {
    Key key;
    int length;
    std::vector<std::vector<std::string>> chords;
  } properties;
};

class Progression {
public:
  Progression(Key key = {"", ""}, int length = 0);

  SongProgression music_get_song_progression(Key key = {"", ""}, int length = 0);
  Key music_random_key();
  std::vector<int> music_progression_steps(int length = 4, bool is_alternative = false);
  std::vector<std::string> music_working_progression(int length, const Key& key, const std::vector<int>& progression_steps);
  std::vector<std::vector<std::string>> music_progression_chords(const std::vector<int>& progression_steps, const Key& key, const std::vector<std::string>& progression);

  SongProgression get_progression() const { return progression_result; }

private:
  SongProgression progression_result;
};

#endif // PROGRESSION_H
