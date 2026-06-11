#include"bits/stdc++.h"
using namespace std;
#define REP(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define rep(i,n) REP((i),0,(n))

int N;
vector<vector<int>> edges;

int dfs(int par, int now) {
	vector<int> res;
	for (int next : edges[now])if (next != par) {
		res.push_back(dfs(now, next));
	}
	if (res.empty())return 0;
	sort(res.begin(), res.end(), greater<int>());
	rep(i, res.size())res[i] += i;
	return *max_element(res.begin(), res.end()) + 1;
}

int main()
{
	cin >> N;
	edges.resize(N);
	REP(i, 1, N) {
		int a;
		cin >> a;
		a--;
		edges[i].push_back(a);
		edges[a].push_back(i);
	}
	cout << dfs(-1, 0) << endl;
	return 0;
}
