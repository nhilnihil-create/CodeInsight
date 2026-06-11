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

int n,m;
int ghead[maxn],gnxt[2*maxn],gto[2*maxn];
int nq;
int qx[maxn],qd[maxn],qc[maxn];

int been[maxn];
int col[maxn];

void dfs(int at,int d,int c)
{
	if (been[at]>=d) return;
	else been[at]=d;
	if (col[at]==0) col[at]=c;
	if (d>0)
	{
		for (int x=ghead[at];x!=-1;x=gnxt[x]) dfs(gto[x],d-1,c);
	}
}

void run()
{
	scanf("%d%d",&n,&m);
	rept(i,0,n) ghead[i]=-1;
	rept(i,0,m)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		gnxt[2*i]=ghead[a];
		ghead[a]=2*i;
		gto[2*i]=b;
		gnxt[2*i+1]=ghead[b];
		ghead[b]=2*i+1;
		gto[2*i+1]=a; 
	}
	scanf("%d",&nq);
	rept(i,0,nq)
	{
		scanf("%d%d%d",&qx[i],&qd[i],&qc[i]);
		qx[i]--;
	}
	CLEAN(been,-1);
	CLEAN(col,0);
	for (int i=nq-1;i>=0;i--) dfs(qx[i],qd[i],qc[i]);
	rept(i,0,n) printf("%d\n",col[i]);
}

int main()
{
	run();
	return 0;
}