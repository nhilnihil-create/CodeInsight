#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i, m) {
    cin >> a[i] >> b[i];
    --a[i]; --b[i];
  }

  vector<int> cnt(n, 0);
  rep(i, m) {
    ++cnt[a[i]];
    ++cnt[b[i]];
  }
  bool exist = true;
  rep(i, n) if (cnt[i] % 2) exist = false;
  if (exist) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}