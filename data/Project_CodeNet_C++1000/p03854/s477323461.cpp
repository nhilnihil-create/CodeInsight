#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool ends_with(const string& str, const string& suffix) {
  return str.size() >= suffix.size() &&
         str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

bool helper(string s) {
  for (;;) {
    if (s.empty())
      return true;

    if (ends_with(s, "dreamer")) {
      s = s.substr(0, s.size() - 7);
    } else if (ends_with(s, "dream")) {
      s = s.substr(0, s.size() - 5);
    } else if (ends_with(s, "eraser")) {
      s = s.substr(0, s.size() - 6);
    } else if (ends_with(s, "erase")) {
      s = s.substr(0, s.size() - 5);
    } else {
      break;
    }
  }

  return false;
}

int main(int argc, char* argv[]) {
  string s;
  cin >> s;

  cout << (helper(s) ? "YES" : "NO") << endl;

  return 0;
}
