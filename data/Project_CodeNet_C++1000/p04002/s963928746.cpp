#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using P = pair<int, int>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	llong H, W, N;
	vector<P> black, masu;

	cin >> H >> W >> N;
	int h,w;
	for(int i = 0; i < N; i++){
		cin >> h >> w;
		black.push_back(P(h,w));
		for(int sh = h-2; sh <= h; sh++){
			for(int sw = w-2; sw <= w; sw++)
				if(1 <= sh && sh <= H-2 && 1 <= sw && sw <= W-2)
					masu.push_back(P(sh,sw));
		}
	}

	sort(BE(black));
	sort(BE(masu));
	masu.erase(unique(BE(masu)), masu.end());

	vector<llong> ans(10,0);
	ans[0] = (H-2)*(W-2) - masu.size();
	for(auto it = masu.begin(); it != masu.end(); it++){
		int res = 0;
		for(int h = it->first; h <= it->first+2; h++)
			for(int w = it->second; w <= it->second+2; w++)
				if(*lower_bound(BE(black), P(h,w)) == P(h,w))
					res++;
		ans[res]++;
	}

	for(auto x : ans)
		cout << x << endl;

	return 0;
}