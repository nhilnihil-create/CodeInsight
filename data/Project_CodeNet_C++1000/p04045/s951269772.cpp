#include <bits/stdc++.h>
using namespace std;
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)

map<int, bool> m;

bool chk(int n) {
  while (n) {
    if (m[n % 10]) {
      return false;
    }
    n /= 10;
  }
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K, k;
  cin >> N >> K;
  rep(i, 0, K) {
    cin >> k;
    m[k] = true;
  }

  while (true) {
    if (chk(N)) {
      cout << N << endl;
      break;
    }
    N++;
  }

  getchar();
}