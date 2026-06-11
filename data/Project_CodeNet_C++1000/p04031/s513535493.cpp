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

	int N;
	vector<int> a;

	cin >> N;
	for(int i=0; i<N; i++){
		long long tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

	sort(a.begin(), a.end());

	long long ans = (1LL<<61);
	for(int i=a[0]-1; i<=a[N-1]+1; i++){
		long long c = 0;
		for(int j=0; j<N; j++){
			c += (a[j] - i) * (a[j] - i);
		}
		if(c < ans){ ans = c;}
	}
	printf("%lld\n", ans);
	return 0;
}