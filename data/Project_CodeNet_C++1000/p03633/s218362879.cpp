#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
  int N;
  cin >> N;
  vector<ll> T(N);
  for (int i = 0; i < N; i++) cin >> T[i];

  ll ans = T[0];
  for (int i = 0; i < N; i++) ans = lcm(ans, T[i]);
  cout << ans << endl;
  return 0;
}
