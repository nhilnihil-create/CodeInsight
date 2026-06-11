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

long long N, x;
vector<long long> a1, a2;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long ans0 = 0;
	cin >> N >> x;
	for(int i=0; i<N; i++){
		long long v;
		cin >> v;
		if(v > x){
			ans0 += (v - x);
			v = x;
		}
		a1.push_back(v);
		a2.push_back(v);
	}
	a1.push_back(0);
	a2.push_back(0);

	long long ans1 = ans0;
	for(int i=1; i<N; i+=2){
		long long v = min(x - a1[i - 1], x - a1[i + 1]);
		if(a1[i] > v){
			ans1 += (a1[i] - v);
			a1[i] = v;
		}
	}
	//printf("ans1=%lld\n", ans1);

	long long ans2 = ans0;
	for(int i=1; i<N; i++){
		long long d = x - a2[i - 1];
		if(a2[i] > d){
			ans2 += (a2[i] - d);
			a2[i] = d;
		}
	}
	//printf("ans2=%lld\n", ans2);
	//printf("%lld\n", min(ans1, ans2));
	printf("%lld\n", ans2);

	return 0;
}