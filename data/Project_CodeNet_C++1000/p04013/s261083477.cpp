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
#include <unordered_map> 
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

LL N,A;
LL x[50];

LL ans = 0;

void solve(){
	//前からi個目まで見た時、そのうちj個を使って合計がk
	//となる組み合わせをいくつ作れるかを
	//dp[i][j][k]とする
	vector<vector<vector<LL>>> dp(N+1,vector<vector<LL>>(N+1,vector<LL>(2501,0)));
	dp[0][0][0] = 1;
	for(int i=0;i<N;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=2500;k++){
				if(dp[i][j][k]>0){
					dp[i+1][j][k] += dp[i][j][k];
					if(k+x[i]<=2500) dp[i+1][j+1][k+x[i]] += dp[i][j][k];
				}
			}
		}
	}
	for(int j=1;j<=N;j++){
		for(int k=1;k<=2500;k++){
			if(k%j==0 && k/j==A){
				ans += dp[N][j][k];
			}
		}
	}
}

int main(){
    cin >> N >> A;
    for(int i=0;i<N;i++) cin >> x[i];

    solve();

	cout << ans << endl;
    return 0;
}