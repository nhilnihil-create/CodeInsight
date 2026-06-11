#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int g1[4][4] = {
  {0, 1, 2, 3},
  {0, 1, 2, 3},
  {2, 3, 0, 1},
  {2, 3, 0, 1},
};

int main() {
  int h, w, d;
  cin >> h >> w >> d;

  vector<string> ans(h, string(w, 0));

  string x = "RYGB";

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int b = (i + j) / d % 2;
      int c = (i - j + d * 1000) / d % 2;
      ans[i][j] = x[(b + c * 2) % 4];
    }
  }
  for (string s : ans) cout << s << endl;
}