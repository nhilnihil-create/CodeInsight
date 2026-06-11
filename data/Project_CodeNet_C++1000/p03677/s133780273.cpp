#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int read()
{
    char c=getchar();int f=1,sum=0;
    while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0' && c<='9'){sum=sum*10+c-'0';c=getchar();}
    return sum*f;
}
int n,m,a[100005];
LL sum[100005],ans=12346567915644LL;
int num[100005];
void add1(int l,int r,int v){sum[l]+=v;sum[r+1]-=v;}
void add2(int l,int r,int v){num[l]+=v;num[r+1]-=v;}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<n;i++)
	{
		int x=a[i],y=a[i+1];
		if(x<y)
		{
			add1(1,x,y-x);
			add1(y+1,m,y-x);
			add1(x+1,y,y+1);
			add2(x+1,y,-1);
		}
		else
		{
			add1(y+1,x,y+m-x);
			add1(x+1,m,y+m+1);
			add2(x+1,m,-1);
			add1(1,y,y+1);
			add2(1,y,-1);
		}
	}
	for(int i=1;i<=m;i++)
	{
		sum[i]+=sum[i-1];
		num[i]+=num[i-1];
		ans=min(ans,(LL)num[i]*i+sum[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
