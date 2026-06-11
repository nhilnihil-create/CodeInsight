#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
using vs = vector<string>;
using in6 = int64_t;
using ind = double;
using pii = pair<int,int>;
using psi = pair<string,int>;
using vpi = vector<pii>;
using vps = vector<psi>;
#define rep(i, n) for (in6 i = 0; i < (in6)(n); i++)
#define repa(i,a,n) for(in6 i = a; i < (in6)(n); i++)
#define repdown(i,n) for(in6 i = n; i > 0; i--)
#define kyun ios::sync_with_stdio(false)
#define hinata cout << "\n"
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define inf 2147483647

int main() {
  kyun;
  int k,t;
  cin >> k >> t;
  vi data(t);
  rep(i,t) cin >> data[i];
  int ans = 0;
  rep(i,t) {
    int a = data[i] - (k - data[i]);
    if(a >= 2) ans += (a - 1);
  }
  cout << ans;
  hinata;
}