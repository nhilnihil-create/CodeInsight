#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int Fennec[N],Snuke[N];
vector<int>g[N];
queue<int>q;
const int INF=1e6+1000;
int main()
{
	int n,a,b,black=0,white=0;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	memset(Fennec,INF,sizeof(Fennec));
	Fennec[1]=0;
	q.push(1);
	while(!q.empty())
	{
		int k=q.front();
		q.pop();
		for(int i=0;i<g[k].size();i++)
		{
			if(Fennec[g[k][i]]>Fennec[k]+1)
			{
				Fennec[g[k][i]]=Fennec[k]+1;
				q.push(g[k][i]);
			}
		}
	}
	memset(Snuke,INF,sizeof(Snuke));
	Snuke[n]=0;
	q.push(n);
	while(!q.empty())
	{
		int k=q.front();
		q.pop();
		for(int i=0;i<g[k].size();i++)
		{
			if(Snuke[g[k][i]]>Snuke[k]+1)
			{
				Snuke[g[k][i]]=Snuke[k]+1;
				q.push(g[k][i]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
  		if(Fennec[i]<=Snuke[i])
			black++;
		else
			white++;
	}
	if(black>white)
		puts("Fennec");
	else
		puts("Snuke");
	return 0;
}