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

long long H, W;
vector<long long> v;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> H >> W ;
	long long S, s, ans, w, h, a, b ,c;

	if((H % 3) == 0 || (W % 3) == 0){
		ans = 0;
		printf("%lld\n", ans);
		return 0;
	}
	
	w = W / 3;
	h = H / 2;
	for(int i = -1; i <= 1; i++){
		if(w+i<1 || w+i>=W) continue;
		for(long long j = -1; j <= 1; j++){
			if(h+j<1 || h+j>=H) continue;
			a = H * (w+i);
			b = (h+j)*(W-(w+i));
			c = (H-(h+j))*(W-(w+i));
			S = max( a, max( b, c ) );
			s = min( a, min( b, c ) );
			v.push_back(S - s);
		}
	}
	
	h = H / 3;
	w = W / 2;
	for(int i = -1; i <= 1; i++){
		if(h+i<1 || h+i>=H) continue;
		for(long long j = -1; j <= 1; j++){
			if(w+j<1 || w+j>=W) continue;
			a = (h+i) * W;
			b = (H-(h+i))*(w+j);
			c = (H-(h+i))*(W-(w+j));
			S = max( a, max( b, c ) );
			s = min( a, min( b, c ) );
			v.push_back(S - s);
		}
	}

	h = H / 3;
	for(int i = -1; i <= 1; i++){
		for(int j= -1; j <= 1; j++){
			a = (h + i) * W;
			b = (h + j) * W;
			c = (H - (h+i) - (h+j)) * W;
            if(a <= 0 || b <= 0 || c <= 0) continue;
			S = max(a, max(b, c));
			s = min(a, min(b, c));
			v.push_back(S - s);
		}
	}

	w = W / 3;
	for(int i = -1; i <= 1; i++){
		for(int j= -1; j <= 1; j++){
			a = (w + i) * H;
			b = (w + j) * H;
			c = (W - (w+i) - (w+j)) * H;
            if(a <= 0 || b <= 0 || c <= 0) continue;
			S = max(a, max(b, c));
			s = min(a, min(b, c));
			v.push_back(S - s);
		}
	}

	sort(v.begin(), v.end());
	ans = v[0];
	printf("%lld\n", ans);
	return 0;
}