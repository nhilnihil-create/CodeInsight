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
vector<long long> a;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long ans = 0;
	cin >> N >> x;
	for(int i=0; i<N; i++){
		long long v;
		cin >> v;
		if(v > x){
			ans += (v - x);
			v = x;
		}
		a.push_back(v);
	}
	a.push_back(0);

	for(int i=1; i<N; i++){
		long long d = x - a[i - 1];
		if(a[i] > d){
			ans += (a[i] - d);
			a[i] = d;
		}
	}
	printf("%lld\n", ans);
	return 0;
}