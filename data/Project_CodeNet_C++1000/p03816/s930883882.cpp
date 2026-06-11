#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
const ll mod = 1000000007;
const ll INF = 9223372036854775807;
#define Sort(a) sort(a.begin(), a.end())
#define Reverse(a) reverse(a.begin(), a.end())
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll d = 0;
  Sort(a);
  rep(i,n-1) {
    if(a[i] == a[i+1]) {
      ++d;
    }
  }
  if (d%2 == 0) n -= d;
  else n -= (d+1);
  cout << n << '\n';
}