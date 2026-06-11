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
	int N, M; cin >> N >> M;
	vector<pair<pair<int,int>,int>> edge(M);
	vector<vector<int>> dis(N + 1, vector<int>(N + 1,1e7));
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge[i].first.first = a, edge[i].first.second = b;
		edge[i].second = c;
		dis[a][b] = c, dis[b][a] = c;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = i; j <= N; j++) {
				if (i == j)dis[i][j] = 0;
				else dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				dis[j][i] = dis[i][j];
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		int a = edge[i].first.first, b = edge[i].first.second, c = edge[i].second;
		if (dis[a][b] != c) cnt++;
	}
	cout << cnt << endl;


}
