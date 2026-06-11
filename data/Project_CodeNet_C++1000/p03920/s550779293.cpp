#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://cf16-final-open.contest.atcoder.jp/tasks/codefestival_2016_final_b>
問題文============================================================
 ある年のCODE FESTIVALの決勝では N 問の問題が出題されました。
 
 i(1≦i≦N) 番目の問題の配点は i 点です。
 
 高橋くんは、このコンテストでちょうど N 点を取りたいと思い、そのために解く問題の集合をどうするかを考えています。
 
 配点が高い問題は難しいので、解く問題の配点のうちの最大値が最小になるようにしようと考えました。
 
 高橋くんが解くべき問題の集合を求めてください。
 

=================================================================

解説=============================================================

================================================================
*/
void solve(ll n,vector<ll>& dp){
    cout << dp[n] << endl;
    if(dp[n] != n) solve(n - dp[n],dp);
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    
    vector<ll> cusum(N+1,0);
    for(int i = 0; i < N;i++) cusum[i+1] = cusum[i] + i;
    vector<ll> dp(N+1,INF);
    for(int i = 1; i <= N;i++){
        dp[i] = lower_bound(cusum.begin(),cusum.end(),i) - cusum.begin() - 1;
    }
    solve(N,dp);
	return 0;
}
