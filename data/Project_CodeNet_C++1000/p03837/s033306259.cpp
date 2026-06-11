#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 102
using namespace std;
int n, m;
int dis[N][N];
int main() {
	vector<pair<pair<int, int>, int>> edges;
	edges.clear();
	cin>>n>>m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dis[i][j] = (i == j ? 0 : 1000000000);
		}
	}
	for (int i = 1; i <= m; ++i) {
		int a,b,c;
		cin>>a>>b>>c;
		edges.push_back(make_pair(make_pair(a,b), c));
		dis[a][b] = dis[b][a] = c;
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j =1 ; j <= n; ++j) {
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
			}
		}
	}
	int cnt=0;
	for (int i = 0; i < edges.size(); ++i) {
		int a = edges[i].first.first;
		int b = edges[i].first.second;
		int c = edges[i].second;
		bool found = false;
		for (int i = 1; i <= n; ++i) {
			if (dis[i][a]+c == dis[i][b] || dis[i][b]+c == dis[i][a]) {
				found=true;
				break;
			}
		}
		if (!found) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}