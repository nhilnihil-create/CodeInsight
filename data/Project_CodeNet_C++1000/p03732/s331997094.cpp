#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
	ll n, W;
	scanf("%lld %lld", &n, &W);
	vector<ll> w(n), v(n);
	scanf("%lld %lld", &w[0], &v[0]);
	vector<vector<ll> > data(4);
	data[0].push_back(v[0]);
	for(int i = 1; i < n; i++){
		scanf("%lld %lld", &w[i], &v[i]);
		data[w[i] - w[0]].push_back(v[i]);
	}
	for(int i = 0; i < 4; i++){
		sort(data[i].begin(), data[i].end(), greater<ll>());
		for(int j = 0; j < data[i].size(); j++){
			if(j == 0) continue;
			data[i][j] += data[i][j - 1];
		}
	}
	ll ans = 0;
	for(int x0 = 0; x0 <= data[0].size(); x0++){
		for(int x1 = 0; x1 <= data[1].size(); x1++){
			for(int x2 = 0; x2 <= data[2].size(); x2++){
				for(int x3 = 0; x3 <= data[3].size(); x3++){
					if(x0 + x1 + x2 + x3 > n) continue;
					if(w[0] * x0 + (w[0] + 1) * x1 + (w[0] + 2) * x2 + (w[0] + 3) * x3 > W) continue;
					ll ans1 = 0;
					if(data[0].size() && x0) ans1 += data[0][x0 - 1];
					if(data[1].size() && x1) ans1 += data[1][x1 - 1];
					if(data[2].size() && x2) ans1 += data[2][x2 - 1];
					if(data[3].size() && x3) ans1 += data[3][x3 - 1];
					ans = max(ans, ans1);
				}
			}
		}
	}
	cout << ans << endl;
}

