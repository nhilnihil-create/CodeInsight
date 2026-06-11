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
  ll n, k, a;
  vector<ll> c(100009, 0);
  in(n);
  rep(i, n){
    in(a);
    c[a - 1]++;
  }
  a = 0;
  k = 0;
  rep(i, 100009){
    if(c[i] != 0){
      a++;
      if(c[i] % 2 == 0)
        k++;
    }
  }
  if(k % 2 == 1)
    a--;
  out(a);
  memi;
}