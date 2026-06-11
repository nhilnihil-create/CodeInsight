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

const ll MOD = 1e9+7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;
  vector<ll> T(N);
  vector<ll> A(N);
  vector<ll> determT(N), determA(N);

  rep(i, N){
    determT[i] = 0;
    determA[i] = 0;
  }
  
  rep(i, N) cin >> T[i];
  rep(i, N) cin >> A[i];

  determT[0] = 1;
  determA[N-1] = 1;

  bool ok = true;
  for(int i = 1; i < N; i++){
    if(T[i] > T[i-1]){
      determT[i] = 1;
    }
  }

  for(int i = N-2; i >= 0; i--){
    if(A[i] > A[i+1]){
      determA[i] = 1;
    }
  }

  for(int i = 0; i < N; i++){
    if(determT[i] && determA[i]){
      if(T[i] != A[i]){
        ok = false;
        break;
      }
    }else if(determT[i] && A[i] < T[i]){
      ok = false;
      break;
    }else if(determA[i] && T[i] < A[i]){
      ok = false;
      break;
    }
  }


  if(ok){

    ll ans = 1;

    rep(i, N){

      if(determT[i] != 1 && determA[i] != 1){
        ans = (ans * min(T[i], A[i])) % MOD;
      }
      
    }
    cout << ans << endl;

  }else{
    cout << 0 << endl;
  }

  return 0;
}
