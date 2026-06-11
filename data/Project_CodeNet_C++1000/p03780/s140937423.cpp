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

const int MAX_N = 5001;
const int MAX_K = 5001;

bool up[MAX_N][MAX_K];
bool down[MAX_N][MAX_K];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  vector<ll> a(N);
  for(int i = 0; i < N; i++) cin >> a[i];

  for(int i = 0; i < MAX_N; i++){
    for(int j = 0; j < MAX_K; j++){
      up[i][j] = false;
      down[i][j] = false;
    }
  }

  up[0][0]   = true;
  down[0][0] = true;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < MAX_K; j++){
      
      if(up[i][j]){
        up[i+1][j] = true;
        up[i+1][min(j+a[i], 5000LL)] = true;
      }
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < MAX_K; j++){

      if(down[i][j]){
        down[i+1][j] = true;
        down[i+1][min(j+a[N-i-1], 5000LL)] = true;
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < N; i++){
    vector<int> vup;
    vector<int> vdown;

    bool ok = true;
    for(int j = 0; j < MAX_K; j++){
      if(up[i][j]) vup.push_back(j);
      if(down[N-(i+1)][j]) vdown.push_back(j);
    }

    for(int j = 0; j < vup.size(); j++){
      auto itr1 = lower_bound(vdown.begin(), vdown.end(), K-a[i]-vup[j]);
      auto itr2 = lower_bound(vdown.begin(), vdown.end(), K-vup[j]);
      if(itr1 != itr2){
        ok = false;
      }
    }
    if(ok){
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
