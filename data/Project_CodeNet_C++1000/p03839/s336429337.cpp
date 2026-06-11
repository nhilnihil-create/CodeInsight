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

  int N, K;
  cin >> N >> K;
  vector<ll> a(N);
  rep(i, N) cin >> a[i];

  vector<ll> suma(N+1);
  vector<ll> sump(N+1);
  rep(i, N){
    suma[i+1] = suma[i] + a[i];
    if(a[i] > 0){
      sump[i+1] = sump[i] + a[i];
    }else{
      sump[i+1] = sump[i];
    }
  }

  ll ans = -1;
  rep(i, N){
    if(i + K - 1 >= N) continue;
    //まず i~i+K-1まで
    ll tans = 0;
    ll blocksum = suma[i+K] - suma[i];
    if(blocksum > 0){
      tans += blocksum;
    }

    // 0~i-1, i+K ~ N-1まで
    tans += sump[i] - sump[0];
    tans += sump[N] - sump[i+K];

    chmax(ans, tans);
    
  }

  cout << ans << endl;

  return 0;
}
