#include<iostream>
#include<cstdio>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include<vector>

using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
#define ll long long
#define rn(i,n) for(int i=1;i<=n;i++)
#define INF 1000000010
const int mo=1e9+7;


ll N, K;
ll a[5000 + 10];

ll dp[5000 + 10][5000 + 10];

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
  
	sort(a, a + N);

	dp[0][0] = 1;
  
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			dp[i + 1][j] += dp[i][j];
			if (j + a[i] < K) {
				dp[i + 1][j + a[i]] += dp[i][j];
			}
		}
	}

	int ans = N;
	for (int i = 0; i < N; i++) {

		ll dplast[5000 + 10] = {};
    
		for (int j = 0; j < K; j++)dplast[j] = dp[N][j];
    
		for (int j = 0; j < K; j++) {
			//dpを一回さし戻す
			if (j + a[i] < K)dplast[j + a[i]] -= dplast[j];
			if (j >= K - a[i] && dplast[j]) {
				ans--;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
