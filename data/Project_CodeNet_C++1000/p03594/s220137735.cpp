#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  const string COLOR = "RGBY";
  ios::sync_with_stdio(false), cin.tie(0);
  int h, w, d; cin >> h >> w >> d;
  int dd = d * 2;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      int y = i + j, x = i - j;
      y = (y % dd + dd) % dd;
      x = (x % dd + dd) % dd;
      cout << COLOR[((y < d) << 1) | (x < d)];
    }
    cout << endl;
  }

}
