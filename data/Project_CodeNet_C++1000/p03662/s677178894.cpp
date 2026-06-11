#include<cstdio>
#include<vector>
using namespace std;
int n, m;
int depth[100010];
int sz[100010];
int parse[100010];
vector<vector<int>> vt;
void dfs(int here, int de)
{
	depth[here] = de;
	sz[here] = 1;
	for (int i = 0; i < vt[here].size(); i++)
	{
		int next = vt[here][i];
		if (!depth[next])
		{
			parse[next] = here;
			dfs(next, de + 1);
			sz[here] += sz[next];
		}
	}
}
int main()
{
	scanf("%d", &n);
	int sum = n;
	vt.resize(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int q, w;
		scanf("%d %d", &q, &w);
		vt[q].push_back(w);
		vt[w].push_back(q);
	}
	dfs(1, 1);
	int ch = depth[n]-depth[1] - 1;
	int ch1 = 0, ch2 = 0;
	ch /= 2;
	while (ch--) {
		n = parse[n];
	}
	ch1 = sz[n];
	ch2 = sum - sz[n];
	if (ch1 >= ch2)
		puts("Snuke");
	else
		puts("Fennec");
}