#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, w;
vector<ll> ww[4];
int main() {
	cin>>n>>w;
	ll w1;
	for (int i = 1; i <= n; ++i) {
		ll tw, v;
		cin>>tw>>v;
		if (i == 1) w1 = tw;
		ww[tw-w1].push_back(v);
	}
	for (int i = 0; i < 4; ++i) {
	//	cout<<"i="<<i<<endl;
		sort(ww[i].begin(), ww[i].end());
		reverse(ww[i].begin(), ww[i].end());
		for (int j = 1; j < ww[i].size(); ++j) {
			ww[i][j] += ww[i][j-1];
		}
	//	cout<<"i1="<<i<<endl;
	}
	ll ans = 0;
	for (int a = 0; a <= ww[0].size(); ++a) {
		for (int b = 0; b <= ww[1].size(); ++b) {
			for (int c = 0; c <= ww[2].size(); ++c) {
				ll totw = (ll)a * (w1+0) + (ll)b*(w1+1) + (ll)c*(w1+2);
				//cout<<a<<" "<<b<<" "<<c<<endl;
				if (totw <= w) {
				//	cout<<"???"<<endl;
					int d = (w - totw) / (w1+3);
					ll totv = (a == 0 ? 0 : ww[0][a-1]) + (b == 0 ? 0 : ww[1][b-1])
					+ (c == 0 ? 0 : ww[2][c-1]);
					if (d > 0) {
						if (d <= ww[3].size()) totv += ww[3][d-1];
						else {
							if (!ww[3].empty()) {
								totv += ww[3].back();
							}
						}
					}
					//if (totv == 12) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
					ans = max(ans, totv);
				}
			//	cout<<"!!!"<<endl;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}