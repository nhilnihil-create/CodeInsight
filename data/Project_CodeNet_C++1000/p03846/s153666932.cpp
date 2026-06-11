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
  ll n, s, p;
  in(n);
  vector<ll> a(n), b(n);
  rep(i, n){
    in(a[i]);
    b[a[i]]++;
  }
  s = 0;
  if(n % 2 == 1){
    rep(i, n){
      if(i == 0){
        if(b[i] != 1)
          s++;
      }
      else if(i % 2 == 0){
        if(b[i] != 2)
          s++;
      }
      else{
        if(b[i] != 0)
          s++;
      }
    }
  }
  else{
    rep(i, n){
      if(i % 2 == 1){
        if(b[i] != 2)
          s++;
      }
      else{
        if(b[i] != 0)
          s++;
      }
    }
  }
  if(s != 0){
    out(0);
    memi;
    return 0;
  }
  s = 0;
  rep(i, n){
    if(b[i] == 2)
      s++;
  }
  p = 1;
  rep(i, s)
    p = p * 2 % mei;
  out(p);
  memi;
}
