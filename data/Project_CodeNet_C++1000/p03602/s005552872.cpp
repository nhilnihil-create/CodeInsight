#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <string>
#include <string.h>
#include <sstream>
#include <ctime>

using namespace std;

#define eps 1e-12
#define pi 3.14159265358979323846
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define bgn begin
#define ll long long
#define ld long double
#define ull unsigned long long
#define ii pair<ll,ll>















const int N=310;
ll n,u,v,w,d[N][N];
ll res;
vector<pair<int,pair<int,int>>>e;









void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)cin>>w;
		for(int j=i+1;j<=n;j++)
		{
			cin>>w;
			e.pb(mp(w,mp(i,j)));
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			d[i][j]=-1;
		}
		d[i][i]=0;
	}
	sort(e.begin(),e.end());
	res=0;
	for(int i=0;i<e.size();i++)
	{
		w=e[i].first;
		u=e[i].second.first;
		v=e[i].second.second;
		if(d[u][v]==-1||d[u][v]>w)
		{
			d[u][v]=w;
			d[v][u]=w;
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(d[j][u]!=-1&&d[k][v]!=-1)
					{
						if(d[j][k]==-1||d[j][u]+d[k][v]+w<d[j][k])
						{
							d[j][k]=d[j][u]+d[k][v]+w;
						}
					}
					if(d[j][v]!=-1&&d[k][u]!=-1)
					{
						if(d[j][k]==-1||d[j][v]+d[k][u]+w<d[j][k])
						{
							d[j][k]=d[j][v]+d[k][u]+w;
						}
					}
				}
			}
			res+=w;
		}
		else if(d[u][v]<w)
		{
			cout<<"-1\n";
			return;
		}
	}
	cout<<res<<"\n";
}

int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
#ifdef localProject
	freopen("in.txt","r",stdin);
#endif
	solve();
	return 0;
}