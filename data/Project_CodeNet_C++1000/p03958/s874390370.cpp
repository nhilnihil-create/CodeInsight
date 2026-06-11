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

LL K, T;
LL ans = 0;

LL getMaxIndex(vector<LL> &v, int t){
	LL ret = -1;
	LL max = -1;
	for(int i=0; i<v.size(); i++){
		if(i == t) continue;
		if(max < v[i] && v[i] > 0){
			max = v[i];
			ret = i;
		}
	}
	return ret;
}

LL eatCake(vector<LL> &v, LL t, LL c){
	LL ret = getMaxIndex(v, t);
	if(ret == -1 && v[t] > 0){
		v[t]--;
		ans++;
		return t;
	}

	v[ret]--;
	return ret;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	vector<LL> A;
	cin >> K >> T;
	for(int i=0; i<T; i++){
		LL a;
		cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end());

	A[A.size()-1]--;
	LL type = T - 1;
	for(int i=1; i<K; i++){
		type = eatCake(A, type, i);
		if(type < 0){
			break;
		}
	}
	printf("%lld\n", ans);
	return 0;
}