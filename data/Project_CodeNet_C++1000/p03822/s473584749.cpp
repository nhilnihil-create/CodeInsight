#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100005;

int n;
int dep[maxn];
vector<int> s[maxn];

inline void dfs(int now)
{
//	cout << now << endl;
	dep[now] = 0;
	priority_queue<int> q;
	for(auto to : s[now])
	{
		dfs(to);
		q.push(dep[to]);
	}
	int tmpp = 0;
	while(!q.empty())
	{
		int top = q.top();
		q.pop();
		dep[now] = max(dep[now], top + (++tmpp));
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 2, t; i <= n; ++i)
	{
		scanf("%d", &t);
		s[t].push_back(i);
	}
	dfs(1);
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans = max(ans, dep[i]);
	printf("%d\n", ans);
	return 0;
}