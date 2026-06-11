#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int k, t;
  cin >> k >> t;
  vector<int> a(t);
  rep(i,t) cin >> a[i];
  sort(rng(a));
  int n = 2 * a[t-1] - k -1;
  if(n<0) cout << 0 << endl;
  else cout << n << endl;
  return 0;
}