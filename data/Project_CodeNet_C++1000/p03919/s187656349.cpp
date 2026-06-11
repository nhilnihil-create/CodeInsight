#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int h, w;
  cin >> h >> w;

  string s[26][26];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> s[i][j];
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] != "snuke") continue;
      printf("%c%d\n", j + 'A', i + 1);
    }
  }

  return 0;
}