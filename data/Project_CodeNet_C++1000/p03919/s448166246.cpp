#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  for (int i = 1; i <= h; ++i) {
    for (char j = 'A'; j - 'A' < w; ++j) {
      string s;
      cin >> s;

      if (s == "snuke") {
        cout << j << i << endl;
      }
    }
  }
}
