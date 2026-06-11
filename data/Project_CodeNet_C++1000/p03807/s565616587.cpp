#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int odd = 0;
  rep(i, 0, n) {
    int a;
    cin >> a;
    if (a & 1)
      odd++;
  }

  if (odd & 1)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
