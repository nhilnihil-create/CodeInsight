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

const ll MOD = 1e9+7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<ll> a(N);
  for(int i = 0; i < N; i++) cin >> a[i];
  
  ll ans = 1;
  queue<ll> q;

  int cnt = 0;
  while(cnt < N){
    
    q.push(a[cnt]);
    ll top = q.back();
    if(top < 2 * q.size() - 1){
      ans = (ans * q.size()) % MOD;
      q.pop();
    }
    cnt++;
  }

  for(ll i = 1; i <= q.size(); i++){
    ans = (ans * i) % MOD;
  }

  cout << ans << endl;

  return 0;
}
