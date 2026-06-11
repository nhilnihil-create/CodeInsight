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
#include <stack>
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

//計算量はどちらもO(logN)
LL gcd(LL a,LL b) { return b?gcd(b,a%b):a;}
LL lcm(LL a,LL b) { return a/gcd(a,b)*b;}

LL N,Ma,Mb;
LL A[40],B[40],C[40];

LL ans = INF;

bool check_rate(LL a,LL b){
	if(a==0 || b==0) return false;
	LL gcd_ab = gcd(a,b);
	return (a/gcd_ab==Ma && b/gcd_ab==Mb);
}

void solve(){
	//dp[i][a][b]
	//i個目まで見た時、タイプAをa[g]、
	//タイプBをb[g]作れるならその最小コスト
	vector<vector<vector<LL>>> dp(N+1,vector<vector<LL>>(401,vector<LL>(401,INF)));
	dp[0][0][0] = 0;
	//ばらまく
	for(int i=0;i<=N-1;i++){
		for(int a=0;a<=399;a++){
			for(int b=0;b<=399;b++){
				if(dp[i][a][b]==INF) continue;
				//i個目を使う
				dp[i+1][a+A[i]][b+B[i]] = min(dp[i+1][a+A[i]][b+B[i]],dp[i][a][b]+C[i]);
				if(check_rate(a+A[i],b+B[i])) ans = min(ans,dp[i+1][a+A[i]][b+B[i]]);
				//i個目を使わない
				dp[i+1][a][b] = min(dp[i+1][a][b],dp[i][a][b]);
				if(check_rate(a,b)) ans = min(ans,dp[i+1][a][b]);
			}
		}
	}
	if(ans==INF) ans = -1;
}

int main(){
    cin >> N >> Ma >> Mb;
    for(int i=0;i<N;i++){
    	cin >> A[i] >> B[i] >> C[i];
    }

    solve();

    cout << ans << endl;
    return 0;
}