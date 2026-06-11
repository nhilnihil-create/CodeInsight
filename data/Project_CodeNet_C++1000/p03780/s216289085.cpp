#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <list>
#include <math.h>
#include <map>
using namespace std;
#define REP(i, k, n) for(int i = k;i < n; i++)
#define rep(i, n) REP(i,0,n)
int dx[4] = {0,-1,1,0};
int dy[4] = {-1,0,0,1};
bool dp[5001][5001];
int tar = 0;
int N, K;
int a[5001];
void solve(int depth, int cost){
	if(depth == N + 1)return;
	if(dp[depth][cost])return;

	dp[depth][cost] = true;
	solve(depth+1, cost);
	if((cost+a[depth] < K) && (tar != depth)){
		solve(depth+1, cost+a[depth]);
	}
}

int main(void){
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	//dp[j枚目まで][総和をxにできるか]
	sort(a, a+N);
	int r = N;
	int l = -1;
	while(r - l > 1){
		tar = (r+l) / 2;
		if(a[tar]>=K){
			r=tar;continue;
		}
		fill_n(*dp, 5001*5001, false);
		// solve(0, 0);
		bool flag = false;
		dp[0][0] = true;
		rep(i,N)rep(j,K+1){
			if(tar == i){
				dp[i+1][j] = dp[i][j];
			}else{
				dp[i+1][j] = dp[i][j];
				if(j-a[i] >= 0){
					dp[i+1][j] = (dp[i][j-a[i]]||dp[i][j]);
				}
			}
		}
		// cout << tar << ", " << a[tar] << endl;
		// rep(i,K){
		// 	cout << dp[N][i] << " ";
		// }cout << endl;
		REP(i,K-a[tar], K){
			flag |= dp[N][i];
		}//cout << (flag?"YES":"NO")<<endl;
		if(!flag){
			l = tar;
		}else{
			r = tar;
		}
	}
	cout << l+1 << endl;
}
/*
20
19 10 9 1
*/
