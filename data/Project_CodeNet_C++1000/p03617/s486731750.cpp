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
typedef long long LL;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL Q, H, S, D;
	LL N;
	cin >> Q >> H >> S >> D;
	cin >> N;

	vector<LL> T;
	T.push_back(8*Q);
	T.push_back(4*H);
	T.push_back(2*S);
	T.push_back(D);
	int p = 0;
	LL m = INF;
	for(int i=0; i<T.size(); i++){
		if(T[i] < m){
			m = T[i];
			p = i;
		}
	}

	LL d = 1;
	LL u = 1;
	if(p == 0){ d = 8; u = Q; }
	else if(p == 1){ d = 4; u = H; }
	else if(p == 2){ d = 2; u = S; }
	else if(p == 3){ d = 1; u = D; }

	LL q = N/2;
	LL r = N%2;
	LL ans = (q*d) * u;
	if(r != 0){
		ans += min(S, min(2*H, 4*Q));
	}
	printf("%lld\n", ans);
	return 0;
}
