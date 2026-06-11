#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;


int main() {
  ll n, p; cin >> n >> p;
  ll o = 0, e = 0;
  rep(i, 0, n){
    ll a; cin >> a;
    if(a%2 == 0) e++;
    else o++;
  }
  if(o == 0){
    if(p == 0) cout << (1LL << n) << endl;
    else cout << 0 << endl;
  }else{
    cout << (1LL << o-1) * (1LL << e) << endl;
  }


  return 0;
}
