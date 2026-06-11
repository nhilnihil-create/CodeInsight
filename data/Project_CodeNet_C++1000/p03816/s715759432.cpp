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
  map<int, int> mp;
  rep(i, 0, n) {
    int a;
    cin >> a;
    mp[a]++;
  }

  int eve = 0;
  for (auto m : mp)
    if (m.second % 2 == 0)
      eve++;

  int subs = 0;
  if (eve & 1)
    subs = 1;

  cout << mp.size() - subs << endl;
}
