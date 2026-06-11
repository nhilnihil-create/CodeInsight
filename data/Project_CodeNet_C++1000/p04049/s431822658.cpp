#include <bits/stdc++.h>
using namespace std;

int n, k;
vector <int> e[2001];
int d[2001][2001];
vector <int> eA, eB;

void dfs(int cur, int from, int root, int curDist)
{
	d[root][cur] = curDist;
	for(int i = 0; i < e[cur].size(); i++)
	{
		int t = e[cur][i];
		if(t != from)
			dfs(t, cur, root, curDist + 1);
	}
}

int MAIN()
{
	cin >> n >> k;
	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
		eA.push_back(a);
		eB.push_back(b);
	}
	for(int i = 1; i <= n; i++)
		dfs(i, -1, i, 0);
	int bestAns = 0;

	for(int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for(int j = 1; j <= n; j++)
			if(2 * d[i][j] <= k)
				cnt ++;
		bestAns = max(bestAns, cnt);
	}
	for(int i = 0; i < eA.size(); i++)
	{
		int a = eA[i];
		int b = eB[i];
		int cnt = 0;
		for(int j = 1; j <= n; j++)
			if(2 * min(d[j][a], d[j][b]) + 1 <= k)
				cnt ++;
		bestAns = max(bestAns, cnt);
	}
	cout << n - bestAns << endl;
	return 0;
}

int main()
{
	int start = clock();
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	int ret = MAIN();
	#ifdef LOCAL_TEST
		cout << "[Finished in " << clock() - start << " ms]" << endl;
	#endif
	return ret;
}
