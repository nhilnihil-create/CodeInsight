#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define mo 1000000007
#define MAX 304
#define fast_io ios::sync_with_stdio(false)
int d[MAX][MAX], a[MAX][MAX];
std::vector<pair<int, pair<int, int> > > v;
int main()
{
	fast_io;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j] = 1e9 + 4;
			int x;
			cin >> x;
			d[i][j] = x;
			v.pb(mp(x,mp(i,j)));
		}

	}
	sort(v.begin(), v.end());
	long long ans = 0;
	for(int i=0;i<v.size();i++)
	{
		int x = v[i].second.first;
		int y = v[i].second.second;
		int temp = 1e9 + 4;
		for(int j=1;j<=n;j++)
		{
			if(j==x || j==y)
				continue;
			if((a[x][j] + a[j][y])<temp)
				temp = a[x][j] + a[j][y];
		}
		if(temp > v[i].first)
		{
			ans += v[i].first;
			a[x][y] = v[i].first;
			a[x][y] = v[i].first;
		}
		else
		{
			a[x][y] = temp;
			a[x][y] = temp;

		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(a[i][j]!=d[i][j])
			{
				cout << -1;
				return 0;
			}
	}
	cout << (ans/2) << "\n";
	return 0;
}