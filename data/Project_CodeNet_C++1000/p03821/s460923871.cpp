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
vector<long long> A, B;
long long btn[100002] = {0};

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i=0; i<N; i++){
		long long a, b;
		cin >> a >> b;
		A.push_back(a);
		B.push_back(b);
	}

	long long ans = 0;
	for(int i=N-1; i>=0; i--){
		long long a;
		if(i == N-1){
			a = A[i];
		}
		else{
			a = A[i] + (btn[i+1] - A[i+1]);
		}
		long long r = a % B[i];
		if(r == 0){
			btn[i] = a;
			continue;
		}
		long long u = B[i] - r;
		ans += u;
		btn[i] = a + u;
	}
	printf("%lld\n", ans);
	return 0;
}
