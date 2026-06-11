#include <bits/stdc++.h>

using namespace std;

int cnt[100005];
bool check[100005];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,m,a,b;
	vector <pair<int,int>> query;

	cin >> n >> m;

	for(int i=0;i<m;i++)
	{
		cin >> a >> b;
		query.push_back(make_pair(a,b));
	}

	for(int i=1;i<=n;i++)
	{
		cnt[i] = 1;
	}
	check[1] = true;

	for(int i=0;i<query.size();i++)
	{
		int a = query[i].first;
		int b = query[i].second;
		cnt[a]-=1;
		cnt[b]+=1;
		if(check[a])
		{
			check[b] = true;
		}
		if(cnt[a]==0)
		{
			check[a] = false;
		}
	}

	int res = 0;

	for(int i=1;i<=n;i++)
	{
		res += check[i];
	}

	cout << res << '\n';
	
	return 0;
}