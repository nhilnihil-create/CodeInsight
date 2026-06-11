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

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N, M; cin >> N >> M;
	vector<int> cnt(M), pac(M);
	map<int, int> mp;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		cnt[x % M]++;
		mp[x]++;
	}

	for (auto p : mp) {
		pac[p.first % M] += p.second / 2;
	}


	ll ans = 0;
	for (int i = 0; i <= M / 2; i++) {
		if (i == 0) ans += cnt[0] / 2;
		else if (i < M / 2) {
			int low = 0, up = 0;
			if (cnt[i] < cnt[M - i]) low = i, up = M - i;
			else low = M - i, up = i;
			ans += cnt[low];
			ans += min((cnt[up] - cnt[low]) / 2, pac[up]);
		}
		else if (i == M / 2) {
			if (M % 2 == 0)ans += cnt[i] / 2;
			else {
				int low = 0, up = 0;
				if (cnt[i] < cnt[M - i]) low = i, up = M - i;
				else low = M - i, up = i;
				ans += cnt[low];
				//cout << "low=" << low << " up=" << up << endl;
				//cout << "i=" << i << " ans=" << ans << endl;
				ans += min((cnt[up] - cnt[low]) / 2, pac[up]);
				//cout << "i=" << i << " ans=" << ans << endl;
			}
		}
		//cout <<"i="<<i<< " ans=" << ans << endl;
	}

	cout << ans << endl;
}
