#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <list>
#include <numeric>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// 最大公約数
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// 最小公倍数
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}*/

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, W;
	cin >> n >> W;
	vector<pair<ll, ll>> wv(n);
	ll baseWeight = inf;
	rep(i, n) {
		cin >> wv[i].first >> wv[i].second;
		baseWeight = min(baseWeight, wv[i].first);
	}
	vector<vector<ll>> wvn(4, vector<ll>());
	rep(i, 4) {
		wvn[i].push_back(0); // 入れないパターン
	}
	rep(i, n) {
		wvn[wv[i].first - baseWeight].push_back(wv[i].second);
	}

	rep(i, 4) {
		sort(wvn[i].begin() + 1, wvn[i].end() , greater<ll>());
	}

	// 重さは4通り
	// 各重さの荷物をそれぞれ何個持っていくか決める
	// 線を三本いれる

	ll ans = 0;
	ll sumw0 = -baseWeight;
	ll sumv0 = 0;
	rep(i, (int)wvn[0].size()) { // 0の個数
		sumw0 += baseWeight;
		sumv0 += wvn[0][i];
		ll sumw1 = -(baseWeight + 1) ;
		ll sumv1 = 0;
		rep(j, (int)wvn[1].size()) { // 1の個数
			sumw1 += baseWeight + 1;
			sumv1 += wvn[1][j];
			ll sumw2 = -(baseWeight + 2);
			ll sumv2 = 0;
			rep(k, (int)wvn[2].size()) { // 2の個数
				sumw2 += baseWeight + 2;
				sumv2 += wvn[2][k];
				ll left = W - sumw0 - sumw1 - sumw2;
				if (left < 0) break;
				ll sumw3 = -(baseWeight + 3);
				ll sumv3 = 0;
				ll sum = sumv0 + sumv1 + sumv2;
				// 残り入れれるだけ入れる
				rep(l, (int)wvn[3].size()) {
					sumw3 += baseWeight + 3;
					sumv3 += wvn[3][l];
					if (left < sumw3) break;
					//cout << i << ", " << j << ", " << k << ", " << l << endl;
					ans = max(ans, sum + sumv3);
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}
