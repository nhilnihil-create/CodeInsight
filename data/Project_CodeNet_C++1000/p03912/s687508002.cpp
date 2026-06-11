#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  vector<int> num(m), pr(m);
  rep(i, n) num[a[i]%m]++;
  rep(i, n-1) {
    if (a[i] == a[i+1]) {
      pr[a[i]%m]++;
      i++;
    }
  }
  int ans = num[0]/2;
  if (m/2+m/2 == m)
    ans += num[m/2]/2;
  for (int i = 1; i < m-i; i++) {
    int p = min(num[i], num[m-i]);
    num[i] -= p;
    num[m-i] -= p;
    ans += p+min(num[i]/2, pr[i])+min(num[m-i]/2, pr[m-i]);
  }
  cout << ans << endl;
  return 0;
}