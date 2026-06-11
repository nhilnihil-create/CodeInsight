#include<bits/stdc++.h>
using namespace std;
long long read()
{
	char ch=getchar();long long x=0,ff=1;
	while(ch<'0'||ch>'9') {if(ch=='-') ff=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return ff*x;
}
void write(long long z)
{
	if(z<0){putchar('-');z=-z;}
	if(z>=10){write(z/10);}
	putchar(z%10+'0');
}
long long n,top;
long long a[100005],zhan[100005];
long long ans[100005],val[100005];
int main()
{
	n=read();
	for(long long i=1;i<=n;++i) 
	{
		a[i]=read();
		val[i]=a[i];
	}
	for(long long i=1;i<=n;++i)
	{
		if(a[i]>a[zhan[top]]) zhan[++top]=i;
		else 
		{
			long long l=0,r=top;
			while(l+1<r)
			{
				long long mid=(l+r)>>1;
				if(a[zhan[mid]]>a[i]) r=mid;
				else l=mid;
			}
			if(a[i]!=a[zhan[r]]) ans[zhan[r]]+=a[i]-a[zhan[r-1]];
		}
	}
	sort(val+1,val+n+1);
	long long now=1;
	for(long long i=1;i<=top;++i) 
	{
		while(now<=n&&val[now]<a[zhan[i]]) now++;
		ans[zhan[i]]+=(a[zhan[i]]-a[zhan[i-1]])*(n-now+1);
	}
	for(long long i=1;i<=n;++i) write(ans[i]),puts("");
	return 0;
}