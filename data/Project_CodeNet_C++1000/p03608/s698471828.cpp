#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll inf = 1000000000;
int n=200,r=200,m=19900;

//vector<pair<int,ll>>adj[n];

int main()
{
	vector<int>towns;
	ll dista=10000000000;
	cin>>n>>m>>r;
	ll dist[n][n];
	ll adm[n][n];
	for(int i=0;i<r;i++){
		int ti;
		cin>>ti;
		towns.push_back(ti-1);
	}
	sort(towns.begin(),towns.end());
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			adm[i][j]=0;
	for(int i=0;i<m;i++)
	{
		int a,b; ll c;
		cin>>a>>b>>c;
		a--;b--;
		//adj[a].push_back({b,c});
		//adj[b].push_back({a,c});
		adm[a][b]=c;
		adm[b][a]=c;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
				dist[i][j]=0;
			else if(adm[i][j])
				dist[i][j]=adm[i][j];
			else
				dist[i][j]=inf;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(dist[j][k]>dist[i][j]+dist[i][k])
					dist[j][k]=dist[i][j]+dist[i][k];
			}
		}
	}
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<dist[i][j]<<" ";
		cout<<"\n";
	}*/
	do{
		ll mind=0;
		for(int i=0;i<towns.size()-1;i++)
		{
			mind += dist[towns[i]][towns[i+1]];
			//cout<<towns[i]<<" "<<towns[i+1]<<" "<<dist[towns[i]][towns[i+1]]<<"\n";
		}
		//cout<<mind<<" \n";
		if(mind<dista){
			dista=mind;
		}
	}while(next_permutation(towns.begin(),towns.end()));
	cout<<dista<<"\n";
}