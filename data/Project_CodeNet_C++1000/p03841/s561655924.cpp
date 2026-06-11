#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <queue>

using namespace std;

const int MAXN = 500 + 100;

int n, p[MAXN];
int ans[MAXN * MAXN];

struct Cmp
{
	bool operator () (int x, int y) const
	{
		return p[x] < p[y];
	}
};

int cnt[MAXN];
priority_queue<int, vector<int>, Cmp> pq;
queue<int> que;

void no()
{
	cout << "No" << endl;
	exit(0);
}

void yes()
{
	cout << "Yes" << endl;
	for(int i = 1; i <= n * n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	exit(0);
}

int main()
{
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> p[i];
	for(int i = 1; i <= n; i++)
	{
		cnt[i] = n - i;
		for(int j = 1; j <= n - i; j++)
			pq.push(i);
		ans[p[i]] = i;
	}
	for(int i = n * n; i >= 1; i--)
		if(ans[i])
		{
			// cerr << i << ' ' << ans[i] << endl;
			if(cnt[ans[i]]) no();
			for(int j = 1; j <= ans[i] - 1; j++)
				que.push(ans[i]);
		}
		else
		{
			if(!pq.empty())
				cnt[pq.top()]--, ans[i] = pq.top(), pq.pop();
			else if(!que.empty())
				ans[i] = que.front(), que.pop();
			else
				no();
		}
	yes();

	return 0;
}
