#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<vector>
#include<cmath>
#include<random>
#include<cassert>
//This code is written by Itst
using namespace std;

int w[107] , val[107] , dp[107][307];
int N , W , allW;

int main(){
	cin >> N >> W;
	for(int i = 1 ; i <= N ; ++i)
		cin >> w[i] >> val[i];
	allW = w[1];
	for(int i = 1 ; i <= N ; ++i) w[i] -= allW;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = N ; j ; --j)
			for(int k = 3 * N ; k >= w[i] ; --k)
				dp[j][k] = max(dp[j][k] , dp[j - 1][k - w[i]] + val[i]);
	int ans = 0;
	for(int i = 1 ; i <= N ; ++i){
		int cur = W - allW * i;
		if(cur < 0) break;
		ans = max(ans , dp[i][min(cur , 3 * N)]);
	}
	cout << ans;
	return 0;
}
