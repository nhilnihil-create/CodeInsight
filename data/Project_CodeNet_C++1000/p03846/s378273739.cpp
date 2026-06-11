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
typedef long long LL;

static LL P = 1000000007;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long N;
	vector<long long> A;

	cin >> N;
	for(int i = 0; i < N; i++){
		long long v;
		cin >> v;
		A.push_back(v);
	}
	sort(A.begin(), A.end());

	long long ans = 0;
	if(N == 1){
		if(A[0] == 0){
			ans = 1;
		}
		else{
			ans = 0;
		}
		printf("%lld\n", ans);
		return 0;
	}

	if((N % 2 == 1)){
		// A は、0, 2, 2, 4, 4, ...のはず
		int match = 1;
		if(A[0] != 0){
			match = 0;
		}
		for(int i = 1; i < N; i++){
			if( (i % 2) == 0 && A[i] != i){
				match = 0;
				break;
			}
			if( (i % 2) == 1 && A[i] != i + 1){
				match = 0;
				break;
			}
		}
		if(match == 1){
			ans = 1;
			// 2**((N-1)/2)
			for(int j = 1; j <= (N - 1) / 2; j++){
				ans = ans * 2;
				ans = ans % P;
			}
			ans = ans % P;
			if(ans < 0) ans += P;
		}
		else{
			ans = 0;
		}
	}
	else if((N % 2) == 0){
		// A は、1, 1, 3, 3, 5, 5, ...のはず
		int match = 1;
		for(int i = 0; i < N; i += 2){
			if(A[i] != (i + 1)){
				match = 0;
				break;
			}
		}
		for(int i = 1; i < N; i += 2){
			if(A[i] != i){
				match = 0;
				break;
			}
		}
		if(match == 1){
			ans = 1;
			for(int j=1; j<=N/2; j++){
				ans = ans * 2;
				ans = ans % P;
			}
			ans = ans % P;
			if(ans < 0) ans += P;
		}
		else{
			ans = 0 ;
		}	
	}
	printf("%lld\n", ans);
	return 0;
}