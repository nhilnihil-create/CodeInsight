#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  string s = "";
  char tmp;
  for (int i = 0; i < H; i++) {
    s.clear();
    for (int j = 0; j < W; j++) {
      cin >> tmp;
      s.push_back(tmp);
    }
    cout << s << endl << s << endl;
  }
  return 0;
}