//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N,W;
LL w[100],v[100];

LL ans = 0;

void solve(){
	//前からi個見た時、
	//とった物の総重量がjのときの
	//最大の総価値をdp[i][j]とおく
	vector<map<LL,LL>> dp(N+1);
	//i個目の物について見ていく
	//ばらまくDP
	for(int i=0;i<N;i++){
		dp[i][0] = 0;
		for(auto iter=dp[i].begin();iter!=dp[i].end();iter++){
			LL j = iter->first;
			//i個目をとるとき
			if(j+w[i]<=W) dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]],dp[i][j]+v[i]);
			//i個目を取らないとき
			dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
		}
	}
	// for(int i=0;i<=N;i++){
	// 	for(auto iter=dp[i].begin();iter!=dp[i].end();iter++){
	// 		printf("dp[%d][%lld]=%lld,",i,iter->first,iter->second);
	// 	}
	// 	cout << endl;
	// }
	for(auto iter=dp[N].begin();iter!=dp[N].end();iter++){
		ans = max(ans,iter->second);
	}
}
 
int main(){
    cin >> N >> W;
    for(int i=0;i<N;i++){
    	cin >> w[i];
    	cin >> v[i];
    }
 
    solve();

	cout << ans << endl;
    return 0;
}