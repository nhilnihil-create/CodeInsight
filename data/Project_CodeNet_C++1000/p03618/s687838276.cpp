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
  ll a, b, n;
  string s;
  in(s);
  n = s.size();
  a = n * (n - 1) / 2;
  vector<ll> c(26, 0);
  char f = 'a';
  rep(i, 26){
    rep(j, n){
      if(f == s[j])
        c[i]++;
    }
    f++;
  }
  rep(i, 26){
    a -= c[i] * (c[i] - 1) / 2;
  }
  out(a + 1);
  memi;
}
