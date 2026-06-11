#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
  string s;
  cin >> s;

  set<char> l;
  for (int i = 0; i < s.size(); ++i) {
    l.insert(s[i]);
  }

  int ret = 1000000;
  for (set<char>::iterator i = l.begin(); i != l.end(); ++i) {
    int tmp = 0;
    int n = s.size();
    char target = *i;
    string t = s;
    while (true) {
      bool changed = false;
      for (int j = 0; j < n - 1; ++j) {
        if (t[j] == target && t[j + 1] == target)
          continue;
        if (t[j] == target || t[j + 1] == target) {
          t[j] = target;
          changed = true;
        }
      }
      if (!changed)
        break;
      ++tmp;
      --n;
    }
    ret = min(ret, tmp);
  }

  cout << ret << endl;

  return 0;
}