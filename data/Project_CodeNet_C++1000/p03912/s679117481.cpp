#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, a[N];
int cnt[N];
vector<int> vec[N];
int res;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		++cnt[a[i]];
	}
	for (int val = 1; val <= 1e5; ++val) {
		for (int i = 1; i <= cnt[val] - cnt[val] % 2; ++i) {
			vec[val % m].push_back(val);
		}
		cnt[val] %= 2;
	}
	for (int val = 1; val <= 1e5; ++val) if (cnt[val]) {
		vec[val % m].push_back(val);
	}

	for (int i = 0; i < m; ++i) {
		int j = (m - i) % m;
		if (i == j) {
			res += vec[i].size() / 2;
			vec[i].clear();
			continue;
		}
		while(vec[i].size() && vec[j].size()) {
			++res;
			vec[i].pop_back();
			vec[j].pop_back();
		}
	}

	for (int i = 0; i < m; ++i) {
		int ptr = 0;
		while(ptr < (int)vec[i].size() - 1) {
			if (vec[i][ptr] == vec[i][ptr + 1]) {
				ptr += 2;
				++res;
			} else {
				++ptr;
			}
		}
	}

	printf("%d\n", res);
}