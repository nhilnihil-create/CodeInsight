#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 998244353
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N, M, R; cin >> N >> M >> R;
	vector<int> r(R);
	for (int i = 0; i < R; i++)
		cin >> r[i];
	vector<vector<int>> dis(N + 1, vector<int>(N + 1,1e8));
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		dis[a][b] = c, dis[b][a] = c;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	sort(r.begin(), r.end());
	vector<int> a(R);
	a = r;
	int ans = 1e8;
	do {
		int temp = 0;
		for (int i = 0; i < R-1; i++) {
			temp += dis[r[i]][r[i + 1]];
		}
		ans = min(ans, temp);
		!next_permutation(r.begin(), r.end());
	} while (r!=a);
	cout << ans << endl;
}