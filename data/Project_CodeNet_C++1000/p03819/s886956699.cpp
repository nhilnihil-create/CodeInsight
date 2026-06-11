#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MAX = 5e5 + 5;
vector<ii> queries[MAX];
vector<int> updates[MAX];
int app[MAX], ans[MAX], bit[MAX];
int n, m;

void update(int idx, int val) {
	while(idx < MAX) {
		bit[idx] += val;
		idx += idx & -idx;
	}
}

int get(int idx) {
	int sum = 0;
	while(idx) {
		sum += bit[idx];
		idx -= idx & -idx;
	}
	return sum;
}

int main() {
	scanf("%d %d", &n, &m);
	fori(i, 1, n + 1) {
		int l, r;
		scanf("%d %d", &l, &r);
		updates[l].push_back(r);
	}

	fori(i, 1, m + 1) {
		for(int j = i; j <= m + i; j += i) {
			int l = j - i, r = j;
			queries[l].emplace_back(r, i);
		}
	}

	ford(i, m, 0) {
		for(auto &each : queries[i]) {
			int r, id;
			tie(r, id) = each;
			ans[id] += get(r);
		}
		for(auto &each : updates[i]) {
			update(each + 1, 1);
		}
	}

	fori(i, 1, m + 1) {
		printf("%d\n", n - ans[i]);
	}

	return 0;
}
