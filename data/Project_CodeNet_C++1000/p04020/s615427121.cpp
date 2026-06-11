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
using Graph = vector<vector<int>>;

typedef long long LL;
static LL INF = (1LL<<62);

LL N;
vector<LL> A;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N;
	A.push_back(0);
	for(int i=0; i<N; i++){
		LL a;
		cin >> a;
		A.push_back(a);
	}

	LL ans = 0;
	for(int i=1; i<=N; i++){
		if(A[i] == 0){
			continue;
		}
		LL u = A[i]/2;
		ans += u;
		if((A[i] % 2) == 0){
			A[i] = 0;
		}
		else{
			A[i] = 1;
			if(i - 1 >= 1 && A[i-1] == 1){
				A[i-1] = 0;
				A[i] = 0;
				ans++;
			}
			else if(i + 1 <= N && A[i+1] > 0){
				A[i+1]--;
				A[i] = 0;
				ans++;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}