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
const LL INF = (1LL<<62)-10e15;
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;
 
LL A,B,C,D,E,F;
 
LL ans1 = 0;//砂糖の量
LL ans2 = 0;//砂糖水の量
 
void solve(){
	//dp[i][j]:
	//砂糖i[g],水j[g]となるようなものが作れるかどうか
	//作れるなら1を代入
	vector<vector<LL>> dp(F+1,vector<LL>(F+1,0));
	dp[0][0] = 1;
	//ばらまくイメージのDP
	for(int i=0;i<=F;i++){
		for(int j=0;j<=F;j++){
			if(!dp[i][j]) continue;
			if(i+j+C<=F) dp[i+C][j] = 1;
			if(i+j+D<=F) dp[i+D][j] = 1;
			if(i+j+100*A<=F) dp[i][j+100*A] = 1;
			if(i+j+100*B<=F) dp[i][j+100*B] = 1;
		}
	}

	for(int i=0;i<=F;i++){
		for(int j=i;j<=F;j++){
			if(!dp[i][j] || i*(100+E)>E*(j+i))continue;
			if(ans1*(i+j)<=i*ans2){
				ans1 = i;
				ans2 = i+j;
			}
		}
	}
}
 
int main(){
    cin >> A >> B >> C >> D >> E >> F;
 
    solve();
 
    cout << ans2 << " " << ans1 << endl;
    return 0;
}