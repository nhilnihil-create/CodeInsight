#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  int anscol = 0, ansrow = 0;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      string s;
      cin >> s;
      if (s == "snuke") {
        anscol = j;
        ansrow = i + 1;
      }
    }
  }

  char c = (anscol%26) + 'A';
  cout << c << ansrow << endl;

  return 0;
}
