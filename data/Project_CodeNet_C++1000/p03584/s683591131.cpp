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

#define DIV 998244353
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	ll N, K; cin >> N >> K;
	vector<pair<ll, ll>> num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i].first >> num[i].second;
	}

	ll ans = 0;
	for (int i = -1; i < 32; i++) {
		if ((i != -1) && !(K & (1 << i)))continue;
		ll temp = 0;
		for (int j = 0; j < N; j++) {
			for (int k = i; k < 32; k++) {
				if (k == i) if (num[j].first & (1 << k))break;
				if ((!(K & (1 << k))) && (num[j].first & (1 << k))) {
					break;
				}
				else if (k == 31) {
					temp += num[j].second;
					//printf("i=%d j=%d\n", i, j);
				}
			}
		}
		ans = max(ans, temp);
	}

	cout << ans << endl;
}
