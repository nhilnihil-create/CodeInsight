#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int ans = 0;
  rep(i,n) {
    if (i < n && a[i] == a[i+1]) {
      while (i < n && a[i] == a[i+1]) i++;
    }

    if (i < n && a[i] < a[i+1]) {
      while (i < n && a[i] <= a[i+1]) i++;
    } else if (i < n && a[i] > a[i+1]) {
      while (i < n && a[i] >= a[i+1]) i++;
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}