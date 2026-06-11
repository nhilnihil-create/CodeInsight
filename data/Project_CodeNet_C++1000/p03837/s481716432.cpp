#include<bits/stdc++.h>
using namespace std;
const int inf=99999999;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[m],b[m],w[m];
	for(int i=0;i<m;i++){cin>>a[i]>>b[i]>>w[i];a[i]--;b[i]--;}

	int dist[n+1][n+1];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(i==j)dist[i][j]=0;
			else dist[i][j]=inf;
		}

	for(int i=0;i<m;i++)
	{
		dist[a[i]][b[i]]=min(dist[a[i]][b[i]], w[i]);
		dist[b[i]][a[i]]=min(dist[b[i]][a[i]], w[i]);
	}

	//floyd warshall

	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
			}

	int ans=m;
	for(int i=0;i<m;i++)
	{
		bool contained=false;
		for(int j=0;j<n;j++)
		{
			if(dist[j][a[i]]+w[i]==dist[b[i]][j])contained=true;
		}
		if(contained)ans--;

	}
	cout<<ans<<"\n";
}