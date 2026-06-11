#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn=1e5+10;

int n,L,T,x[maxn],y[maxn];
bool w[maxn];

int main()
{
#ifdef h10
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int i,tmp;
	scanf("%d%d%d",&n,&L,&T);
	for (i=1;i<=n;i++)
		scanf("%d%d",&x[i],&tmp),w[i]=tmp==1;
	for (i=1;i<=n;i++)
		y[i]=w[i]?(x[i]+T)%L:((x[i]-T)%L+L)%L;
	int id=1;
	for (i=2;i<=n;i++)
		if (w[i]!=w[1])
		{
			int d0=w[1]?(x[i]-x[1]+L)%L:(x[1]-x[i]+L)%L;
			if (2*T<d0) continue;
			if (w[1]) id+=1+(2*T-d0)/L;
			else id-=1+(2*T-d0)/L;
			id=((id-1)%n+n)%n+1;
		}
	int pos1=y[1];
	sort(y+1,y+n+1);
	for (i=1;i<=n;i++)
		if (y[i]==pos1) break;
	if (y[i]==y[i+1]&&w[1]) i++;
	tmp=((i-id)%n+n)%n+1;
	for (i=tmp;i<=n;i++)
		printf("%d\n",y[i]);
	for (i=1;i<tmp;i++)
		printf("%d\n",y[i]);
}
