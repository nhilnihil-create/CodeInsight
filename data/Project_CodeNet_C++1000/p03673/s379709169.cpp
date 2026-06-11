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

  int ni = n-1;
  while (ni > 0) {
    cout << a[ni] << " ";
    ni -= 2;
  }
  cout << a[0] << " ";
  if (n % 2 == 1) ni = 1;
  else ni = 2;
  while (ni < n) {
    cout << a[ni] << " ";
    ni += 2;
  }
  return 0;
}