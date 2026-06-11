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

long long N, T;
vector<long long> t;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> T;
	for(int i=0; i<N; i++){
		long long tmp;
		cin >> tmp;
		t.push_back(tmp);
	}

	long long ans = T;
	long long laststop = T;
	for(int i=1; i<N; i++){
		if(laststop < t[i]){
			ans = ans + T;
		}
		else{
			ans = ans + (t[i] - (laststop -T));
		}
		laststop = t[i] + T;
	}
	printf("%lld\n", ans);
	return 0;
}
