 #include <bits/stdc++.h>
 using namespace std;
 typedef long long int ll;
  
 // 配列が大きいのでグローバル変数にしてます、あとlong longも忘れずに
 ll dp[55][55][2600] = {};  // i番目までで、k回選んで合計をsにする組み合わせの数
  
 // ====================================================================
  
 int main() {
   ll n, a;
   cin >> n >> a;
   vector<ll> v(n);
   for (int i = 0; i < n; i++) cin >> v[i];
  
   // 俗に言う配るDP
   dp[0][0][0] = 1;  // 初期化
   for (int i = 0; i <= n; i++) {
     for (int k = 0; k <= 50; k++) {
       for (int s = 0; s <= 2500; s++) {
         dp[i + 1][k][s] += dp[i][k][s]; // そのカードを選ばなかった場合
         dp[i + 1][k + 1][s + v[i]] += dp[i][k][s]; // そのカードを選んだ場合
       }
     }
   }
  
   ll ans = 0;
   for (int k = 1; k <= n; k++)
     ans += dp[n][k][a * k]; // k回選んで合計がa*k(つまり平均はa)の組み合わせの数を足す
  
   cout << ans << endl;
 }