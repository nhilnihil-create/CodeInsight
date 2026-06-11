#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define pa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
#define pb push_back

using ll = long long;
using namespace std;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
const int INFint = 1e9;
const ll INFll = 1e18;
ll MOD=1e9+7;

ll gcd(ll a, ll b) { return __gcd(a,b); } //最大公約数
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; } //最大公倍数

// aのn乗をMODで割りながら計算する
ll modpow(ll a, ll n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % MOD;
    a = a * a % MOD;
    n >>= 1; // right shift
  }
  return res;
}

// MODを法としたaの逆元を計算する
ll modinv(ll a) {
  return modpow(a, MOD - 2);
}

int main(){
  int N,M,R;
  cin>>N>>M>>R;
  vector<vector<int>> d(N,vector<int>(N,INFint));
  vector<int> r(R);
  for (int i(0);i<R;i++){
     cin>>r[i];
     r[i]--;
  }
  for (int i(0);i<M;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--;
    b--;
    d[a][b] = c;
    d[b][a] = c;
  }
  for (int k = 0; k < N; k++){       // 経由する頂点
    for (int i = 0; i < N; i++) {    // 始点
      for (int j = 0; j < N; j++) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  sort(r.begin(),r.end());
  int ans(1e9);
  do{
    int tmp(0);
    for (int i(0);i<R-1;i++){
      tmp += d[r[i]][r[i+1]];
    }
    ans = min(ans,tmp);
  }while(next_permutation(r.begin(),r.end()));
  cout << ans << endl;
  return 0;
}

