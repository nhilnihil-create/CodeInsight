#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define MOD (ll)(1e9+7)
#define INF INT32_MAX
#define INFL INT64_MAX
using namespace std;

void solve()	{
	int n,m;
	cin >> n >> m;
	pair<int,int>	s[n], cp[m];
	for(int i=0; i<n; i++)	{
		int x,y;
		cin >> x >> y;
		s[i] = {x,y};
	}
	for(int i=0; i<m; i++)	{
		int x,y;
		cin >> x >> y;
		cp[i] = {x,y};
	}
	for(int i=0; i<n; i++)	{
		int mx = INF,ans;
		for(int j=0; j<m; j++)	{
			if(mx>abs(s[i].first-cp[j].first)+abs(s[i].second-cp[j].second))	{
				ans = j+1;
				mx = abs(s[i].first-cp[j].first)+abs(s[i].second-cp[j].second);
			}
		}
		cout << ans << endl;
	}
}

int main()	
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin >> t;
	for(int i=1; i<=t; i++)	{
		solve();
	}
	return 0;
}