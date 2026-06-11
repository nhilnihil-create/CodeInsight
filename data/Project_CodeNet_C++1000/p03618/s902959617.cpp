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
  ll n;
  n = s.length();

  vector<vector<ll>> a(26);
  
  rep(i, s.length()){

    a[s[i]-'a'].push_back(i);

  }

  vector<ll> cnt(26);
  vector<ll> cntp(26);
  rep(i, 26){
    cntp[i] = 0;
    cnt[i] = a[i].size();
    rep(j, a[i].size()-1){
      if(a[i][j+1] - a[i][j] == 1){
        cntp[i]++;
      }
    }
  }

  ll tans = 0;
  rep(i, 26){
    tans += cnt[i] * (cnt[i]-1) / 2 + cnt[i];
  }

  cout << n * (n+1)/2 - tans + 1 << endl;

  return 0;
}
