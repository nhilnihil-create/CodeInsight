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

int N, A, B;
short a[40], b[40], c[40];

vector<vector<vector<short>>> dp(40);
short solve(short n, short A, short B){
	if(A < 0 || B < 0) return 4001;
	if(n == N){
		if(A == 0 && B == 0) return 0;
		else return 4001;
	}
	if(dp[n][A][B] != -1) return dp[n][A][B];
	return dp[n][A][B] = min(solve(n+1, A, B), (short)(solve(n+1, A-a[n], B-b[n])+c[n]));
}

signed main(){
	cin >> N >> A >> B;
	rep(i, N) cin >> a[i] >> b[i] >> c[i];
	short ans = 4001;
	rep(i, 40){
		dp[i].resize(401);
		rep(j, 401){
			dp[i][j].assign(401, -1);
		}
	}
	for(int i=1; i*A<=400&&i*B<=400; i++){
		ans = min(ans, solve(0, i*A, i*B));
	}
	if(ans > 4000) cout << -1 << endl;
	else cout << ans << endl;
}
