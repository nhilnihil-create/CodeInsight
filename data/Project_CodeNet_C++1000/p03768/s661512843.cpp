#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
const int inf=2147483647,dx[]={-1,0,1,0},dy[]={0,-1,0,1};
const long long llinf=9223372036854775807ll;
const int N=100005;
int a[N][3],ma[N],ans[N],bfs[N];
vector<int> g[N];
void go(int in[])
{
	int x=in[0]-1,dd=in[1],v=in[2];
	if(dd<ma[x])
		return ;
	ma[x]=dd;
	bfs[0]=x;
	int rr=1;
	for(int i=0;i<rr;i++)
	{
		int x=bfs[i];
		if(!ans[x])
			ans[x]=v;
		if(!ma[x])
			continue;
		for(int i=0;i<g[x].size();i++)
		{
			int y=g[x][i];
			int nd=ma[x]-1;
			if(nd>ma[y])
			{
				ma[y]=nd;
				bfs[rr++]=y;
			}
		}
	}
}
int n,m,q,x,y;
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		x--,y--;
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	cin>>q;
	for(int i=0;i<q;i++)
		for(int j=0;j<3;j++)
			cin>>a[i][j];
	for(int i=0;i<N;i++)
		ma[i]=-1;
	for(int i=q;i>=0;i--)
		go(a[i]);
	for(int i=0;i<n;i++)
		cout<<ans[i]<<'\n';
	return 0;
}