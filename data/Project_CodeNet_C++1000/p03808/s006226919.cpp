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
  vector<ll> A(N);

  ll sum = 0;
  for(int i = 0; i < N; i++){
    cin >> A[i];
    sum += A[i];
  }
  
  ll block_sum = N * (N+1LL)/ 2;

  if(sum % block_sum == 0){
    ll cnt = sum / block_sum; // 操作回数

    vector<ll> diff(N);
    for(int i = 0; i < N-1; i++){
      diff[i] = A[i] - A[i+1] + cnt;
    }

    diff[N-1] = A[N-1] - A[0] + cnt;

    ll cnt_tmp = 0;
    bool ok = true;
    for(int i = 0; i < N; i++){
      if(diff[i] % N == 0 && diff[i] / N >= 0){
        cnt_tmp += diff[i] / N;
      }else{
        ok = false;
      }
    }

    if(ok && cnt_tmp == cnt){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }else{
    cout << "NO" << endl;
  }

  return 0;
}
