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
  ll n, a, b, k;
  in2(n, k);
  vector<ll> c(n);
  rep(i, n)
    in(c[i]);
  bool h = false;
  rep(i, n - 1){
    if(c[i] + c[i + 1] >= k){
      a = i;
      h = true;
    }
  }
  if(!h){
    out("Impossible");
    memi;
    return 0;
  }
  out("Possible");
  memi;
  rep(i, a){
    out(i + 1);
    memi;
  }
  b = n - 2;
  while(b >= a){
    out(b + 1);
    memi;
    b--;
  }
}