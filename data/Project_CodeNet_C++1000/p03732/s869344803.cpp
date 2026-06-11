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

LL N, W;
vector<LL> VV;
vector<LL> VW;
map<pair<LL, LL>, LL> M;

LL val(LL i, LL w){
	auto p = make_pair(i, w);
	if(M.count(p) != 0){
		return M[p];
	}
	LL ret;
	if(i == 0){
		if(VW[0] <= w){
			ret = VV[0];
		}
		else{
			ret = 0;
		}
		M[make_pair(i, w)] = ret;
		return ret;
	}
	if(VW[i] > w){
		ret = val(i-1, w);
	}
	else{
		ret = max(val(i-1, w-VW[i]) + VV[i], val(i-1, w));
	}
	M[make_pair(i, w)] = ret;
	return ret;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> W;
	for(int i=0; i<N; i++){
		LL w, v;
		cin >> w >> v;
		VV.push_back(v);
		VW.push_back(w);
	}
	printf("%lld\n", val(N-1, W));
	return 0;
}
