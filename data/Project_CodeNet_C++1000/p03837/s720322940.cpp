#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n,m;
	cin>>n>>m;
	int a[m],b[m],c[m];
	set<pair<int,int>>edges[n][n];
	int dist[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++){
			if(i==j)
				dist[i][j]=0;
			else
				dist[i][j]=100000;
		}
	}
	for(int i=0;i<m;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		a[i]--;
		b[i]--;
	}
	for(int i=0;i<m;i++)
	{
		dist[a[i]][b[i]]=min(dist[a[i]][b[i]],c[i]);
		dist[b[i]][a[i]]=min(dist[b[i]][a[i]],c[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{

				dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);

				}
			}
		}
	
		int ans=m;
		for(int i=0;i<m;i++)
		{
			bool inc=false;
			for(int j=0;j<n;j++)
			{
				if(dist[j][a[i]]+c[i]==dist[j][b[i]])
					inc=true;
			}
			if(inc==true)
				ans--;
		}

cout<<ans<<"\n";

}