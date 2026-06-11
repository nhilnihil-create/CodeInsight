#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, a, n) for(ll i = a; i < (ll)(n); i++)
#define memi cout << endl
#define kono(n) cout << fixed << setprecision(n)
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define hina cout << ' '
#define in(n) cin >> n
#define in2(n, m) cin >> n >> m
#define in3(n, m, l) cin >> n >> m >> l
#define out(n) cout << n
const ll mei = (ll)1e9 + 7;

int main(){
  ll n, a, b, d;
  in(n);
  vector<ll> c(n);
  rep(i, n)
    in(c[i]);
  rep(i, n){
    if(c[i] % 4 == 0)
      c[i] = 2;
    else if(c[i] % 2 == 0)
      c[i] = 1;
    else
      c[i] = 0;
  }
  a = b = 0;
  rep(i, n){
    if(c[i] == 0)
      a++;
    if(c[i] == 2)
      b++;
  }
  if(a > b){
    if(a == b + 1 && n - a - b == 0)
      out("Yes");
    else
      out("No");
  }
  else
    out("Yes");
  memi;
}