#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 510000;
const int MOD = 1000000007;

/*long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}*/
int main() {
  int N;
  cin >> N;
  vector<ll> A(N);

  for (int i = 0; i < N; i++)
  {
      /* code */
      cin >> A[i];
  }

  map<ll, int> p;

  for (int i = 0; i < N; i++)
  {
      p[A[i]] += 1;
  }
  
  bool hantei = false;
  vector<ll> g;
  vector<ll> t;
  ll ans = 0;
  for(auto i : p) {
     
      if (i.second > 1) { g.push_back(i.first); }
      if (i.second >= 4) { t.push_back(i.first); }
  }
  if(g.size() < 2) { cout << 0 << endl; return 0; }
  sort(g.begin(), g.end());
  reverse(g.begin(), g.end());
  ans = g[0] * g[1];
  for (auto i : t) {
      if ( ans < i * i) ans = i * i;
  }
  cout << ans << endl;

    return 0;
}