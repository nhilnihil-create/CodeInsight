#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, K, x, s = 0;
  cin >> N >> K;
  rep(i, N) {
    cin >> x;
    s += min(x, K - x);
  }
  cout << 2 * s << endl;
}