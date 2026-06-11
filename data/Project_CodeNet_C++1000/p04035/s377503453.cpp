#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

  ll N, L;
  cin >> N >> L;
  vector<ll> a(N);
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }

  ll max_ind = 0;
  ll max_len = -1;
  for(int i = 0; i < N-1; i++){
    if(chmax(max_len, a[i]+a[i+1])){
      max_ind = i;
    }
  }

  if(max_len < L){
    cout << "Impossible" << endl;
  }else{
    cout << "Possible" << endl;
    for(int i = 0; i < max_ind; i++){
      cout << (i+1) << endl;
    }
    for(int i = N-2; i >= max_ind; i--){
      cout << (i+1) << endl;
    }
  }



  return 0;
}
