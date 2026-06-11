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
	long long S, s, ans;

	if((H % 3) == 0 || (W % 3) == 0){
		ans = 0;
		printf("%lld\n", ans);
		return 0;
	}

	long long w, h;
	v.clear();

	//左1/3、残りの右を上下に分割
	w = W / 3;
	h = H / 2;
	// H*w, h*(W-w), (H-h)*(W-w)
	for(long long i = -2; i <= 2; i++){
		if(w+i<1 || w+i>=W) continue;
		for(long long j = -2; j <= 2; j++){
			if(h+j<1 || h+j>=H) continue;
			long long a = H * (w+i);
			long long b = (h+j)*(W-(w+i));
			long long c = (H-(h+j))*(W-(w+i));
			if(a <= 0 || b <= 0 || c <= 0) continue;
			S = max( a, max( b, c ) );
			s = min( a, min( b, c ) );
			if(S >= s && S > 0 && s > 0){
				v.push_back(S - s);
			}
		}
	}
	
	//上1/3、残りの下を左右に分割
	h = H / 3;
	w = W / 2;
	// h*W, (H-h)*w, (H-h)*(W-w) 
	for(long long i = -2; i <= 2; i++){
		if(h+i<1 || h+i>=H) continue;
		for(long long j = -2; j <= 2; j++){
			if(w+j<1 || w+j>=W) continue;
			long long a = (h+i) * W;
			long long b = (H-(h+i))*(w+j);
			long long c = (H-(h+i))*(W-(w+j));
			if(a <= 0 || b <= 0 || c <= 0) continue;
			S = max( a, max( b, c ) );
			s = min( a, min( b, c ) );
			if(S >= s && S > 0 && s > 0){
				v.push_back(S - s);
			}
		}
	}

	//縦方向に3分割
	h = H / 3;
	for(int i = -2; i <= 2; i++){
		for(int j= -2; j <= 2; j++){
			long long a = (h + i) * W;
			long long b = (h + j) * W;
			long long c = (H - (h+i) - (h+j)) * W;
			if(a <= 0 || b <= 0 || c <= 0) continue;
			S = max(a, max(b, c));
			s = min(a, min(b, c));
			if(S >= s && S > 0 && s > 0){
				v.push_back(S - s);
			}
		}
	}

	//横方向に3分割
	w = W / 3;
	for(int i = -2; i <= 2; i++){
		for(int j= -2; j <= 2; j++){
			long long a = (w + i) * H;
			long long b = (w + j) * H;
			long long c = (W - (w+i) - (w+j)) * H;
			if(a <= 0 || b <= 0 || c <= 0) continue;
			S = max(a, max(b, c));
			s = min(a, min(b, c));
			if(S >= s && S > 0 && s > 0){
				v.push_back(S - s);
			}
		}
	}

	sort(v.begin(), v.end());
	ans = v[0];
	printf("%lld\n", ans);
	return 0;
}