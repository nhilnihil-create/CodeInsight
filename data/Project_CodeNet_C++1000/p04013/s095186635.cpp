//
//  main.cpp
//  ProblemSolving
//
//  Created by Mac mini on 1/7/20.
//  Copyright © 2020 Mac mini. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
long long int  dp[51][51][1000];
int x[52], n, a;

long long int call(int idx, int cnt, int amount) {
	if(idx >= n) {
		if((double)amount / cnt == a)
			return 1;
		return 0;
	}

	if(dp[idx][cnt][amount] != -1) return dp[idx][cnt][amount];

	long long int  ret1 = 0, ret2 = 0;

	ret1 = call(idx + 1, cnt + 1, amount + x[idx]);
	ret2 = call(idx + 1, cnt, amount);

	dp[idx][cnt][amount] = ret1 + ret2;

	return dp[idx][cnt][amount];
}

int main() {
	cin >> n >> a;

	for(int i = 0; i < n; i++){
		cin >> x[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << call(0, 0, 0) << "\n";

}
