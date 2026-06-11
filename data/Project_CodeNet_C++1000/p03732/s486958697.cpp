#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

int N;
ll W;
ll w[100], v[100];

ll dp[105][105][305];
ll solve(int n, int m, int k){
    if(w[0]*m+k > W) return LLONG_MIN;
    if(n == N) return 0;
    if(dp[n][m][k] != -1) return dp[n][m][k];
    return dp[n][m][k] = max(solve(n+1, m, k), solve(n+1, m+1, k+w[n]-w[0])+v[n]);
}

signed main(){
    cin >> N >> W;
    rep(i, N) cin >> w[i] >> v[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, 0) << endl;
}