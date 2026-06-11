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

  string s, t;
  cin >> s >> t;

  vector<int> sA(s.length()+1), tA(t.length());
  sA[0] = 0;
  tA[0] = 0;

  rep(i, s.length()){
    if(s[i]=='A'){
      sA[i+1] = sA[i] + 1;
    }else{
      sA[i+1] = sA[i];
    }
  }

  rep(i, t.length()){
    if(t[i] == 'A'){
      tA[i+1] = tA[i] + 1;
    }else{
      tA[i+1] = tA[i];
    }
  }

  int q;
  cin >> q;
  vector<bool> ans(q);

  rep(i, q){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    a--;
    c--;

    int v1 = (b-a) - 2 * (sA[b] - sA[a]);
    int v2 = (d-c) - 2 * (tA[d] - tA[c]);

    if(abs(v1 - v2) % 3 == 0){
      ans[i] = true;
    }else{
      ans[i] = false;
    }

  }

  rep(i, q){
    if(ans[i]){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }



  return 0;
}
