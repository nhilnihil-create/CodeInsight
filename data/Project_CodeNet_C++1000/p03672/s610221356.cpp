#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  if (s.size() % 2 == 0) {
    s.erase(s.size() - 2);
  } else {
    s.erase(s.size() - 1);
  }

  int len = 0;
  while (s.size() > 0) {
    int mid = s.size() / 2;
    string t = s.substr(0, mid);
    t += t;

    if (s == t) {
      len = s.size();
      break;
    }

    s.erase(s.size() - 2);
  }
  cout << len << endl;

  return 0;
}
