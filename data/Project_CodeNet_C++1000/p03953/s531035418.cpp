#include<bits/stdc++.h>
using namespace std;
long long read()
{
	char ch=getchar();long long x=0,ff=1;
	while(ch<'0'||ch>'9') {if(ch=='-') ff=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*ff;
}
void write(long long aa)
{
	if(aa<0) putchar('-'),aa=-aa;
	if(aa>9) write(aa/10);
	putchar(aa%10+'0');
	return;
}
long long n,m,K;
long long a[100005],b[100005],tmp[100005];
void ksm(long long aa)
{
	while(aa)
	{
		if(aa&1) 
		{
			for(long long i=1;i<=n;++i) tmp[i]=a[b[i]];
			for(long long i=1;i<=n;++i) a[i]=tmp[i];
		}
		aa>>=1;
		for(long long i=1;i<=n;++i) tmp[i]=b[b[i]];
		for(long long i=1;i<=n;++i) b[i]=tmp[i];
	}
	return;
}
int main()
{
	n=read();
	for(long long i=1;i<=n;++i) a[i]=read(),b[i]=i;
	for(long long i=n;i>=1;--i) a[i]-=a[i-1];
	m=read(),K=read();
	for(long long i=1;i<=m;++i) 
	{
		long long x=read();
		swap(b[x],b[x+1]);
	}
	ksm(K);
	long long sum=0;
	for(long long i=1;i<=n;++i)
	{
		sum+=a[i];
		write(sum);
		puts("");
	}
	return 0;
}
