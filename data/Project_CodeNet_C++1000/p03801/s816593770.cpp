#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int,int> ii;

map<int,int> cnt, first_pos;
priority_queue<int> pq;

int n;
int a[100001], ans[100001];

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int pre = -1;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		if (!cnt.count(a[i]))
		{
			pq.push(a[i]);
			first_pos[a[i]] = i;
		}	
		cnt[a[i]]++;
	}
	while(!pq.empty())
	{
		if (first_pos[pq.top()] == 1)
		{
			ans[1] += cnt[pq.top()]*pq.top();
			pq.pop();
			while(!pq.empty())
			{
				ans[1] += cnt[pq.top()]*pq.top();
				pq.pop();
			}			
		}
		else
		{
			int cur_pos = first_pos[pq.top()];
			int cur_val = pq.top();
			pq.pop();
			ans[cur_pos] += cnt[cur_val]*(cur_val - pq.top());
			if(first_pos[pq.top()] > cur_pos)
				first_pos[pq.top()] = cur_pos;
			cnt[pq.top()] += cnt[cur_val];
		}
	}
	for (int i=1;i<=n;i++)
		cout << ans[i] << '\n';
}