#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<vector<ll>> dis(n,vector<ll>(n,1e9));
	for(int i = 0;i<n;i++)dis[i][i]=0;

	vector<pair<pair<ll,ll>,ll>> input(m);
	for(int i = 0;i<m;i++)
	{
		cin >> input[i].first.first >> input[i].first.second >> input[i].second;
		input[i].first.first --;
		input[i].first.second--;
		dis[input[i].first.first][input[i].first.second] = input[i].second;
		dis[input[i].first.second][input[i].first.first] = input[i].second;
	}
	for(int k = 0;k<n;k++)
	{
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<n;j++)
			{
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int cnt = 0;
	for(int i =0;i<m;i++)
	{
		int x = input[i].first.first;
		int y = input[i].first.second;
		int c = input[i].second;
		if(dis[x][y] != c) cnt++;
	}
	cout << cnt << endl;
	


}
