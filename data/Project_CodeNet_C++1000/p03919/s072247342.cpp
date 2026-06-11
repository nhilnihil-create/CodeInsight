#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      string name;
      cin >> name;
      if (name == "snuke") {
        cout << char('A' + j) <<  (i + 1) << endl;
      }
    }
  }
  return 0;
}