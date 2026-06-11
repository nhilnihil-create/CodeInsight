#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<string>> data(h, vector<string>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> data.at(i).at(j);
    }
  }
  int a, b;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (data.at(i).at(j) == "snuke") {
        a = i;
        b = j;
      }
    }
  }
  char c = b + 1 + 64;
  cout << c << a + 1 << endl;
}
