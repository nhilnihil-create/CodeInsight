#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn=1e5+10;
const int maxm=4e5+10;

int n,m,size,col[maxn],Point,BG,UBG;
int tote,FIR[maxn],TO[maxm],NEXT[maxm];

void addedge(int u,int v)
{
	TO[++tote]=v;
	NEXT[tote]=FIR[u];
	FIR[u]=tote;
}

bool search(int u)
{
	bool flag=1;
	size++;
	for (int p=FIR[u];p;p=NEXT[p])
	{
		int v=TO[p];
		if (!col[v])
			col[v]=3-col[u],flag&=search(v);
		else
			flag&=col[u]+col[v]==3;
	}
	return flag;
}

int main()
{
#ifdef h10
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int i,u,v;
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	for (i=1;i<=n;i++)
		if (!col[i])
		{
			size=0; col[i]=1;
			if (search(i))
				size==1?Point++:BG++;
			else
				size==1?Point++:UBG++;
		}
	printf("%lld\n",2ll*Point*n-(LL)Point*Point+((LL)BG+UBG)*(BG+UBG)+(LL)BG*BG);
}
