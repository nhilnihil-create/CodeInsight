#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(ll i = (s); i < (n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
  
  ll n;
  cin >> n;
  ll odd = 0;
  rep(i, 0, n) {
    ll a;
    cin >> a;
    if(a %2 == 1) odd++;
  }
  cout << ( odd %2 == 0 ?"YES" :"NO") << "\n";
}