#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int n;
  ll ans = 0;
  cin >> n;
  vector<int> t(n),a(n);
  REP(i,n) cin >> t[i] >> a[i];

  ll tt = t[0], aa = a[0];
  for (int i = 1; i < n; i++) {
    if (t[i] == t[i-1] && a[i] == a[i-1]) continue;
    ll div = max(tt/t[i], aa/a[i]);
    while (t[i]*div < tt || a[i]*div < aa) div++;
    tt = t[i]*div; aa = a[i]*div;
  }
  cout << tt + aa << endl;
}