#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  vector<vector<int>> ind(26);
  rep(i, 26){
    ind[i].push_back(0);
  }

  rep(i, s.length()){
    ind[s[i]-'a'].push_back(i+1);
  }

  int ans = 1000;

  rep(i, 26){
    if(ind[i].size()==1) continue;

    int max_val = -1;
    rep(j, ind[i].size()-1){
      chmax(max_val, ind[i][j+1] - ind[i][j]-1);
    }

    chmin(ans, max(max_val, int(s.length() - ind[i][ind[i].size()-1])));

  }

  cout << ans << endl;




  return 0;
}
