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

  int N;
  cin >> N;
  vector<ll> a(3*N);
  for(int i = 0; i < 3*N; i++) cin >> a[i];

  vector<ll> left_vec(N+1);

  ll sum_tmp = 0;
  multiset<ll> ms;
  for(int i = 0; i < N; i++){
    ms.insert(a[i]);
    sum_tmp += a[i];
  }

  left_vec[0] = sum_tmp;

  for(int i = 0; i < N; i++){
    // a[i]を追加し、最小の値を削除
    ms.insert(a[N+i]);
    ll min_val = *ms.begin();
    left_vec[i+1] = left_vec[i] + a[N+i] - min_val;
    ms.erase(ms.begin());

  }

  vector<ll> right_vec(N+1);
  sum_tmp = 0;
  multiset<ll> ms2;
  for(int i = 0; i < N; i++){
    ms2.insert(a[3*N-1-i]);
    sum_tmp += a[3*N-1-i];
  }
  right_vec[0] = sum_tmp;
  for(int i = 0; i < N; i++){
    ms2.insert(a[2*N-1-i]);
    auto itr_max = ms2.end();
    itr_max--;
    right_vec[i+1] = right_vec[i] + a[2*N-1-i] - *itr_max;
    ms2.erase(itr_max);
  }

  ll ans = -INF;
  for(int i = 0; i < N+1; i++){
    chmax(ans, left_vec[i] - right_vec[N-i]);
  }
  
  cout << ans << endl;

  return 0;
}
