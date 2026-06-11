#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> c(h);
  for (int i = 0; i < h; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < 2 * h; i++) {
    for (int j = 0; j < w; j++) {
      cout << c[i / 2][j];
    }
    cout << endl;
  }
  return 0;
}