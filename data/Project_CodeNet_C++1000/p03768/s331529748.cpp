//**************************
//*** writer  :  Alex Hu **
//************************

#include<bits/stdc++.h>

using namespace std;

#define CLEAN(a,b) memset(a,b,sizeof(a))
#define mkp make_pair
#define pb push_back
#define rept(i,a,b) for(int i=(int)(a);i<(int)(b);i++)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi; 

const int maxn=1e5+10;

vi adj[maxn];
int mindis[maxn];
int color[maxn];
int v[maxn];
int d[maxn];
int c[maxn];

void dfs(int node,int dleft,int Cin)
{
	if (dleft<=mindis[node]) return;
	mindis[node]=dleft;
	if (color[node]==0) color[node]=Cin;
	rept(i,0,adj[node].size())
	{
		int to=adj[node][i];
		dfs(to,dleft-1,Cin);
	}	
}

int main()
{
	int n,m,q;
	scanf("%d%d",&n,&m);
	rept(i,0,n) mindis[i]=-1;
	rept(i,0,m)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	scanf("%d",&q);
	rept(i,0,q) scanf("%d%d%d",v+i,d+i,c+i);
	for (int i=q-1;i>=0;i--) dfs(v[i]-1,d[i],c[i]);
	rept(i,0,n) printf("%d\n",color[i]);
    return 0;
}