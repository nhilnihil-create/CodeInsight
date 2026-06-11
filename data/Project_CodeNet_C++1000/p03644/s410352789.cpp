#include <bits/stdc++.h>
using namespace std;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)

inline unsigned f(unsigned n) {
  unsigned cnt = 0;
  while (n % 2 == 0) {
    n /= 2;
    cnt++;
  }
  return cnt;
}

void solve() {
  int N;
  cin >> N;
  unsigned mx = 0;
  unsigned ans = 0;
  for (int i = 2; i <= N; i += 2) {
    int chk = f(i);
    if (mx < chk) {
      mx = chk;
      ans = i;
    }
  };
  cout << ((N == 1) ? 1 : ans) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}