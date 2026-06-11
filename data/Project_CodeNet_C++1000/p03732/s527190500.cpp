#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>

#define rep(i,n) for(ll i=0;i<n;i++)
#define dup(x,y) (((x)+(y)-1)/(y)) // dup * y >= x なる最小のdup.
using namespace std;
typedef long long ll;
using Graph = vector<vector<ll>>;
//	std::cout<<std::fixed<<std::setprecision(10);

// 普通のKnapsack問題ではなかった
int main() {
	ll N, W;
	cin >> N >> W;

	vector<vector<ll>> wv(4);
	vector<vector<ll>> v_sum(4);

	ll w1, v1;
	cin >> w1 >> v1;
	wv[0].push_back(v1);
	rep(i, N-1) {
		ll w, v;
		cin >> w >> v;
		wv[w-w1].push_back(v);
	}

	rep(i, 4) {
		sort(wv[i].begin(), wv[i].end());
		reverse(wv[i].begin(), wv[i].end());
		rep(j, wv[i].size()+1) {
			if(j==0) v_sum[i].push_back(0);
			else v_sum[i].push_back(v_sum[i][j-1] + wv[i][j-1]);
		}
	}
	
	// rep(i, 4) {
	// 	cout << "v_sum: ";
	// 	rep(j, v_sum[i].size()) {
	// 		cout << v_sum[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }

	ll ans = 0;
	for(int d=min((int)(W/(w1+3)), (int)wv[3].size()); d>=0; d--) {
		ll restd = W - d*(w1+3);
		int c = min((int)(restd/(w1+2)), (int)wv[2].size());

		for(; c>=0; c--) {
			ll restc = restd - c*(w1+2);
			ll b = min((int)(restc/(w1+1)), (int)wv[1].size());

			for(; b>=0; b--) {
				ll restb = restc - b*(w1+1);
				int a = min((int)(restb/w1), (int)wv[0].size());

				ll val = v_sum[0][a] + v_sum[1][b] + v_sum[2][c] + v_sum[3][d];
				// cout << "v " << val  << '|' << a << ' ' << b << ' ' << c << ' ' << d << endl; 
				ans = max(val, ans);
			}
		}
	}
	
	cout << ans << endl;

	return 0;
}