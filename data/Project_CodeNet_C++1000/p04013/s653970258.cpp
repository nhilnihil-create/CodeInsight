#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;
ll dp[50][51][2501];	// i番目以降で構成される配列で、j個の数字を使って、kという数字を作る場合の数
int numList[50];

void init(){
	for(int i = 0; i < 50; i++){
		for(int j = 0; j < 51; j++){
			for(int k = 0; k < 2501; k++)dp[i][j][k] = -1;
		}
	}
}

ll dfs(int target,int n,int startIndex,int N){	// n 個の数を使って targetを作る場合の数を返す
	if(startIndex == N) return 0;
	if(n == 0) return 0;
	if(target <= 0) return 0;
	if(dp[startIndex][n][target] != -1) return dp[startIndex][n][target];
	if(n == 1){
		int count = 0;
		for(int i = startIndex; i < N; i++){
			if( numList[i] == target) count++;
		}
		dp[startIndex][n][target] = count;
		return count;
	}
	
	if( numList[startIndex] > target){
		dp[startIndex][n][target] = 0;
		return 0;
	}
	ll ans = 0;
	//numList[startIndex] を使う場合と使わない場合の二通りの和を返す
	int a = numList[startIndex];
	ans += dfs(target,n,startIndex + 1,N); //使わない場合
	ans += dfs(target-a,n-1,startIndex+1,N);
	dp[startIndex][n][target] = ans;
	return ans;
}

int main()
{
	init();
	ll N,A;
	cin>>N>>A;
	rep(i,N) cin>>numList[i];
	sort(numList,numList+N);
	ll ans = 0;
	for(int i = 1 ; i <= N; i++){
		ans += dfs(A*i,i,0,N);
	}
	cout<<ans<<endl;
	return 0;
}
