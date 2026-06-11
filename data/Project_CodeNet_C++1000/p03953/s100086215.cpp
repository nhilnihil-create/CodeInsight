#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

#define dd ch=getchar()
inline int read()
{
	int x=0;bool f=false;char dd;
	while(!isdigit(ch))f|=ch=='-',dd;
	while(isdigit(ch))x=(x<<1)+(x<<3)+ch-48,dd;
	return f?-x:x;
}
#undef dd
void write(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+48);
}
#define writeln(x) (write(x),putchar('\n'))

const int N=100005,mod=998244353;
int o[N],n,m;
ll k;
int tmp[N],a[N],b[N];

signed main()
{
//	freopen("qwq.in","r",stdin);
//	freopen("qwq.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		o[i]=read();
	for(int i=1;i<=n;i++)
		a[i]=o[i]-o[i-1];
	for(int i=1;i<=n;i++)
		b[i]=i;
	cin>>m>>k;
	for(int i=1,x;i<=m;i++)
	{
		x=read();
		swap(b[x],b[x+1]);
	}
	
	for(;k;k>>=1)
	{
		if(k&1)
		{
			memcpy(tmp,a,sizeof(a));
			for(int i=1;i<=n;i++)
				a[i]=tmp[b[i]];
		}
		memcpy(tmp,b,sizeof(b));
		for(int i=1;i<=n;i++)
			b[i]=tmp[tmp[i]];
	}
	
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		printf("%.1lf\n",(double)sum);
	}
	return 0;
}