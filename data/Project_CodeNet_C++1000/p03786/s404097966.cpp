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
	for(int i=0; i<N; i++){
		LL a;
		cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end());

	vector<LL> S;
	for(int i=0; i<A.size(); i++){
		if(i == 0){
			S.push_back(A[0]);
		}
		else{
			S.push_back(S[i-1] + A[i]);
		}
	}

	LL ans = 1;
	for(int i=S.size()-1; i>=1; i--){
		if(S[i-1] * 2 >= A[i]){
			ans++;
		}
		else{
			break;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

