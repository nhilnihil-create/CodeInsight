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

//最大公約数
ll gcd(ll a, ll b){
  if (a%b == 0) {
    return(b);
  } else {
    return(gcd(b, a%b));
  }
}

int main() {
  ll n, k; cin >> n >> k;
  Vl a(n);
  rep(i, 0, n){ 
    cin >> a[i];
    if(a[i] == k){
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }
  bool f = true;
  rep(i, 0, n){
    if(a[i] >= k){ 
      f = false;
      }
  }
  if(f){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  sort(ALL(a));

  ll g = a[0];
  rep(i, 1, n-1){
    g = gcd(g, a[i]);
  }

  if(k%g == 0) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;

  return 0;
}
