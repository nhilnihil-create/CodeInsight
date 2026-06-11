#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;


int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long N, M;
	cin >> N >> M;

	long long ans = 0;
	if(N > M/2){
		ans =  M / 2;
	}
	else{
		ans = (M + 2 * N) / 4;
	}
	printf("%lld\n", ans);
	return 0;
}