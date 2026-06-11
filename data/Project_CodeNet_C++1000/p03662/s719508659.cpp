#include <bits/stdc++.h>
#define INF 1000000009
using namespace std;

vector<int> bfs(int n,vector<vector<int> >& g,int s)
{
	vector<int> d(n,INF);
	d[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int t=q.front();q.pop();
		for(int i=0;i<g[t].size();i++) if(d[g[t][i]]>d[t]+1){
			d[g[t][i]]=d[t]+1;
			q.push(g[t][i]);
		}
	}
	
	return d;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int> > g(n);
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	vector<int> d1=bfs(n,g,0);
	vector<int> d2=bfs(n,g,n-1);
	int n1=0,n2=0;
	for(int i=0;i<n;i++) if(d1[i]<=d2[i]) n1++;else n2++;
	if(n1>n2) cout<<"Fennec"<<endl;
	else cout<<"Snuke"<<endl;
	return 0;
}