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

  int n;
  cin >> n;
  vector<int> a(n);

  int amax = -1;
  int amin = 200;
  map<int, int> mp;
  rep(i, n){
    cin >> a[i];
    chmax(amax, a[i]);
    chmin(amin, a[i]);
    mp[a[i]]++;
  }

  if(amax%2==0){

    if(amin != amax/2){
      cout << "Impossible" << endl;
      return 0;
    }

    if(mp[amin] != 1){
      cout << "Impossible" << endl;
      return 0;
    }

    for(int i = amin+1; i <= amax; i++){
      if(mp[i] < 2){
        cout << "Impossible" << endl;
        return 0;
      }
    }

    cout << "Possible" << endl;
  }else{

    if(amin != (amax+1)/2){
      cout << "Impossible" << endl;
      return 0;
    }

    if(mp[amin] != 2){
      cout << "Impossible" << endl;
      return 0;
    }

    for(int i = amin+1; i <= amax; i++){
      if(mp[i] < 2){
        cout << "Impossible" << endl;
        return 0;
      }
    }
    
    cout << "Possible" << endl;

  }

  return 0;
}
