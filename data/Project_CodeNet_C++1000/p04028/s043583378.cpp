#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream> 
#include<map>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <iomanip>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
long long dp[5500][6000] = {};
long long inv(long long vary){
	long long geko = MAX_MOD-2;
	long long ans = 1;
	while(geko != 0){
		if(geko % 2 == 1){
			ans *= vary;
			ans %= MAX_MOD;
		}
		geko /= 2;
		vary *= vary;
		vary %= MAX_MOD;
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	dp[0][0] = 1;
	for(int i = 1;i <= n;++i){
		for(int q = 0;q <= n;++q){
			if(q != 0) dp[i][q] += 2*dp[i-1][q-1];
			else dp[i][q] += dp[i-1][q];
			dp[i][q] += dp[i-1][q+1];
			dp[i][q] %= MAX_MOD;
		}
	}
	long long hoge = 1;
	for(int i = 0;i < s.length();++i){
		hoge *= 2;
		hoge %= MAX_MOD;
	}
	cout << (dp[n][s.length()] * inv(hoge))%MAX_MOD << endl;
	return 0;
}
