#include <bits/stdc++.h>
#define sp ' '
#define mkp make_pair
#define intmax 2147483647
#define llmax 9223372036854775807
#define lP pair<ll,ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;
const int mod = 1000000007;
const int mod998 = 998244353;

int N, K, a[100000], res, d[100000];
vector<int>r[100000];
priority_queue<pair<int, int>>q;
void dfs(int x, int dis) {
	d[x] = dis;
	q.push(mkp(dis, x));
	for (int i : r[x]) {
		dfs(i, dis + 1);
	}
}

void dfs2(int x) {
	d[x] = 0;
	for (int i : r[x]) {
		if (d[i])dfs2(i);
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	if (a[0] != 1)++res;
	for (int i = 1; i < N; ++i) {
		r[a[i] - 1].push_back(i);
	}
	dfs(0, 0);
	while (!q.empty()) {
		if (d[q.top().second] > K) {
			int t = q.top().second;
			for (int i = 1; i < K; ++i) {
				t = a[t] - 1;
			}
			dfs2(t);
			++res;
		}
		q.pop();
	}
	cout << res << endl;
	return 0;
}