#include <vector>
#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 10;

vector<int> G[MAX_N];
int A[MAX_N];
bool flag = true;

long long dfs(int u, int fa)
{
	if (G[u].size() == 1)
		return A[u];
	long long sum = 0;
	long long mx = 0;
	for (int v : G[u])
	{
		if (v == fa)
			continue;
		long long t = dfs(v, u);
		sum += t;
		mx = max(mx, t);
	}
	long long mxp = mx > sum - mx ? sum - mx : sum / 2;
	long long p = sum - A[u];
	long long rem = A[u] - p;
	if (p < 0 || p > mxp)
		flag = false;
	return rem;
}

int main()
{
	int N; cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> A[i];
	for (int i = 1; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if (N == 2)
	{
		cout << (A[1] == A[2] ? "YES" : "NO") << endl;
		return 0;
	}
	int rt = 0;
	for (int i = 1; i <= N; ++i)
		if (G[i].size() > 1)
			rt = i;
	cout << (dfs(rt, 0) == 0 && flag ? "YES" : "NO") << endl;
	return 0;
}
