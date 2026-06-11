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

int ans[110][110];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H, W, N;
  cin >> H >> W >> N;
  vector<int> a(N);
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }

  int tmp_cnt = 0;
  int tmp_color = 0;

  for(int i = 0; i < H; i++){
    if(i%2 == 0){
      for(int j = 0; j < W; j++){
        ans[i][j] = tmp_color;
        tmp_cnt++;
        if(tmp_cnt == a[tmp_color]){
          tmp_color++;
          tmp_cnt= 0;
        }
      }
    }else{
      for(int j = W-1; j >= 0; j--){
        ans[i][j] = tmp_color;
        tmp_cnt++;
        if(tmp_cnt == a[tmp_color]){
          tmp_color++;
          tmp_cnt = 0;
        }
      }
    }
  }

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cout << ans[i][j]+1 << " ";
    }
    cout << endl;
  }
  return 0;
}
