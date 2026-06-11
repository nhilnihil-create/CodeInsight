#include<bits/stdc++.h> 
using namespace std;
int N;
vector<int> g[100001];
int dist[2][100001],id;
void dfs(int idx,int par=-1)
{
	if(~par) dist[id][idx]=dist[id][par]+1;
	for(auto &to  :  g[idx]) if(to!=par) dfs(to,idx);
} 
int main()
{
	cin>>N;
	for(int i=0;i<N-1;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	id=0;
	dfs(0);
	id=1;
	dfs(N-1);
	int ret=0;
	for(int i=0;i<N;i++)
	{
		if(dist[0][i]<=dist[1][i])
			ret++;
	}
	if(ret>=(N+2)/2)
	    printf("Fennec\n");
    else
        printf("Snuke\n");
	return 0;
}