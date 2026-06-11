#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, w; scanf("%d%d", &h, &w);
  string s;
  int rx, ry;
  for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
    cin >> s;
    if (s == "snuke") {
      ry = i;
      rx = j;
    }
  }
  cout << char('A' + rx) << ry + 1 << endl;
}
 
