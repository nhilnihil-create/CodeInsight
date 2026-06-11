#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define x first
#define y second
int32_t main()
{
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>> s(n), c(m);
	for(int i=0;i<n;i++)
	{
		cin>>s[i].x>>s[i].y;
	}
	for(int i=0;i<m;i++)
	{
		cin>>c[i].x>>c[i].y;
	}
	int sx,sy;
	for(int i=0;i<n;i++)
	{
		sx=s[i].x;sy=s[i].y;
		int mn=1e18;
		for(int j=0;j<m;j++)
		{
			mn=min(mn,abs(sx-c[j].x)+abs(sy-c[j].y));
		}
		for(int j=0;j<m;j++)
		{
			if(abs(sx-c[j].x)+abs(sy-c[j].y)==mn)
			{
				cout<<j+1<<"\n";
				break;
			}
		}
	}

}