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

	long long N;
	vector<long long> S, T;
	long long max = 0;

	cin >> N;
	for(int i=0; i<N; i++){
		long long tmp;
		cin >> tmp;
		S.push_back(tmp);
		max += tmp;
	}

	sort(S.begin(), S.end());

	long long ans = 0;
	if((max % 10) != 0){
		ans = max;
	}
	else{
		for(int i=0; i<N; i++){
			if((S[i] % 10) != 0){
				ans = max - S[i];
				break;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
