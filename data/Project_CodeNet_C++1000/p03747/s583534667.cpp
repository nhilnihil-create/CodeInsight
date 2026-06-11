#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
int x[100010];
int w[100010];
int y[100010];
int n,l,t;
int x1[100010];
int x2[100010];
int x3[100010];
int x4[100010];
int t1=0,t2=0,t3=0,t4=0;
void rd(int &s)
{
	int c;
	while((c=getchar())<'0'||c>'9');
	s=c-'0';
	while((c=getchar())>='0'&&c<='9')
		s=s*10+c-'0';
}
int main()
{
#ifdef DEBUG
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	scanf("%d%d%d",&n,&l,&t);
	int len=t%l;
	int i;
	int c=0;
	for(i=1;i<=n;i++)
	{
		rd(x[i]);
		rd(w[i]);
		if(w[i]==1)
		{
			c+=(t+x[i])/l;
			y[i]=(x[i]+len)%l;
			if(y[i]>=len)
				x3[++t3]=y[i];
			else
				x1[++t1]=y[i];
		}
		else
		{
			c-=(t-x[i]+l-1)/l;
			y[i]=(x[i]-len+l)%l;
			if(y[i]>=l-len)
				x4[++t4]=y[i];
			else
				x2[++t2]=y[i];
		}
		c%=n;
	}
	c=(c+n)%n;
	for(i=1;i<=t3;i++)
		x1[++t1]=x3[i];
	for(i=1;i<=t4;i++)
		x2[++t2]=x4[i];
	int cnt=0,j=1;
	i=1;
	while(i<=t1||j<=t2)
	{
		if(j>t2||(i<=t1&&x1[i]<=x2[j]))
			y[++cnt]=x1[i++];
		else
			y[++cnt]=x2[j++];
	}
	for(i=c+1;i<=n;i++)
		printf("%d\n",y[i]);
	for(i=1;i<=c;i++)
		printf("%d\n",y[i]);
	return 0;
}