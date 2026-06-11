#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;  // vi <=> vl
using P = pair<int, int>;  // int <=> ll
const int MOD = 1e9+7;
const double EPS = 1e-9;

int main() {
  ll n, x; cin >> n >> x;
  ll a = n-x, b = x;
  if (a < b) swap(a,b);
  ll ans = n;
  while (a%b) {
    ans += a/b * 2*b;
    a %= b;
    swap(a,b);
  }
  ans += a*2 - b;
  cout << ans << endl;
  return 0;
}
