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

int n;
vector<int> G[100100];

int dfs(int v){

  int ret = 0;
  
  vector<int> vec_val;
  for(auto nv : G[v]){

    int tans = dfs(nv);

    vec_val.push_back(tans);    
  }

  sort(vec_val.rbegin(), vec_val.rend());

  rep(i, vec_val.size()){
    chmax(ret, vec_val[i] + i + 1);
  }

  return ret;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;

  rep(i, n-1){

    int a;
    cin >> a;
    a--;
    // a -> iへの辺
    G[a].push_back(i+1);

  }

  int ans = 0;
  ans = dfs(0);

  cout << ans << endl;

  return 0;
}
