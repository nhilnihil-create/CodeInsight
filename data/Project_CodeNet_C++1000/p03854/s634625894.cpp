#include <iostream>
#include <vector>

using namespace std;

  vector<string> phrases = {"dream", "dreamer", "erase", "eraser"};

int main() {
  string target_str;
  cin >> target_str;


  string tmp_phrase = "";

  bool constractable = true;
  for(int i = target_str.size() - 1; i >= 0; i--) {
    tmp_phrase = target_str[i] + tmp_phrase;

    bool is_match = false;
    for(int j = 0; j < phrases.size(); j++) {
      if(phrases[j].size() < tmp_phrase.size()) {
        continue;
      }

      if(phrases[j].substr(phrases[j].size() - tmp_phrase.size(), tmp_phrase.size()) == tmp_phrase) {
        is_match = true;
      }

      // clear tmp phrase
      if(tmp_phrase == phrases[j]) {
        tmp_phrase = "";
        break;
      }
    }

    if(!is_match) {
      constractable = false;
      break;
    }
  }

  if(constractable) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

}