#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
#define M 2e5
using namespace std;
using ll = long long;
using ldb = long double;

void comb(vector<vector<ll>> &c) {
	int H = c.size(), W = c[0].size();
	for (int i = 0; i < H; i++) {
		c[i][0] = 1;
	}

	for (int n = 1; n < H; n++) {
		for (int r = 1; r < W; r++) {
			c[n][r] = c[n - 1][r] + c[n - 1][r - 1];
		}
	}

}

int main() {
	ldb N, A, B; cin >> N >> A >> B;
	vector<ll> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<ll>());
	ll sum = 0, mi = 1e16;
	map<ldb, int> mp;
	int C = 0;
	for (int i = 0; i < N; i++) {
		if (i < A) {
			sum += v[i];
			mi = min(mi, v[i]);
		}
		mp[v[i]]++;
		if (i == A - 1) C = mp[mi];
	}

	ldb mean = (ldb)sum / A;
	printf("%.10Lf\n", mean);

	vector<vector<ll>> c(51, vector<ll>(51));
	comb(c);

	int D = mp[mi];
	if (C < A) {
		ll temp = c[D][C];
		cout << temp << endl;
	}

	else {
		ll ans = 0;
		for (int i = A; i <= B; i++) {
			ll temp = c[D][i];
			ans += temp;
			//cout << ans << endl;
		}
		cout << ans << endl;
	}

}