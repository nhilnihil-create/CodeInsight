#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, answer = "None";
  cin >> s;
  vector<char> c(26, 0);
  for (int i = 0; i < s.size(); i++) c[(int)s.at(i) - (int)'a']++;//s[i]がaなら0,zなら25を増やす
  for (int i = 0; i < 26; i++) {
    if (c[i] == 0) {
      answer = (char)((int)'a' + i);
      break;
    }
  }
  cout << answer;
}