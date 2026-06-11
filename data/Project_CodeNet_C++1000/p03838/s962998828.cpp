#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl;
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;



int main() {
  ll x, y; cin >> x >> y;
  
  ll ans = INF;

  Rep(i, 0, 1){
    Rep(j, 0, 1){
      ll a = pow(-1, i)*x;
      ll b = pow(-1, j)*y;
      if(b >= a) chmin(ans, i+j+b-a);
    }
  }

  cout << ans << endl;

  return 0;
}