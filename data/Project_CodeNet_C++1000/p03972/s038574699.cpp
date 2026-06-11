#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int W, H, i;
	scanf("%lld%lld", &W, &H);
	vector<int> p(W), q(H);
	for(i = 0; i < W; i++){
		scanf("%lld", &p[i]);
	}
	for(i = 0; i < H; i++){
		scanf("%lld", &q[i]);
	}
	vector<pair<int, pair<int, int>>> es(0);
	for(i = 0; i < W; i++){
		es.push_back(pair<int, pair<int, int>>(p[i], pair<int, int>(0, i)));
	}
	for(i = 0; i < H; i++){
		es.push_back(pair<int, pair<int, int>>(q[i], pair<int, int>(1, i)));
	}
	sort(es.begin(), es.end());
	int connect_num[2] = {W + 1, H + 1};
	int ans = 0;
	for(i = 0; i < W + H; i++){
		int cost = es[i].first, d = es[i].second.first, k = es[i].second.second;
		ans += connect_num[1 - d] * cost;
		connect_num[d]--;
	}
	printf("%lld\n", ans);
	return 0;
}