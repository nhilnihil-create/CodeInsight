#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,x;
  cin >> N >> x;
  int ans[(2*N) - 1];
  if (x == 1 || x == (2*N) - 1) {
    cout << "No" << endl;
    return 0;
  } else {
    cout << "Yes" << endl;
  }
  if (x == 2 && N == 2) {
    cout << 1 << endl;
    cout << 2 << endl;
    cout << 3 << endl;
    return 0;
  }
  if (x == 2) {
    ans[N-3] = 3;
    ans[N-2] = 2;
    ans[N-1] = 1;
    ans[N] = 4;
    int cnt = 5;
    for (int i = 0; i < (2*N) - 1; i++) {
      if (i > N || i < N - 3) {
        ans[i] = cnt;
        cnt++;
      }
    }
  } else {
    ans[N-3] = x - 1;
    ans[N-2] = x;
    ans[N-1] = x + 1;
    ans[N] = x - 2;
    int cnt = 1;
    if (x == 3) {
      cnt = 5;
    }
    for (int i = 0; i < (2*N) - 1; i++) {
      if (N - 3 <= i && i <= N) {
        continue;
      }
      ans[i] = cnt;
      if (cnt == x - 3) {
        cnt = x + 2;
      } else {
        cnt++;
      }
    }
  }

  for (int i = 0; i < (2*N) - 1; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}