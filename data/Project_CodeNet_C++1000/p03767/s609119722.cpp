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
long long INF = (1LL<<62);

long long N;
vector<long long> A;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i=0; i<3*N; i++){
		long long a;
		cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end());

	long long ans = 0;
	for(int i=A.size()-2; i>=N; i -= 2){
		ans += A[i];
	}
	printf("%lld\n", ans);
	return 0;
}