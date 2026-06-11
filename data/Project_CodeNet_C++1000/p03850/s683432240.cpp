#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
template <typename T>inline T read()
{
    register T sum=0;
    register char cc=getchar();
    int sym=1;
    while(cc!='-'&&(cc>'9'||cc<'0'))cc=getchar();
    if(cc=='-')sym=-1,cc=getchar();
    sum=sum*10+cc-'0';
    cc=getchar();
    while(cc>='0'&&cc<='9')sum=sum*10+cc-'0',cc=getchar();
    return sym*sum;
}
template <typename T>inline T read(T &a)
{
    a=read<T>();
    return a;
}
template <typename T,typename... Others> inline void read(T& a, Others&... b)
{
    a=read(a);
	read(b...);
}
int n,l=1,r,a[maxn],flg[maxn];
long long ans=-1e18,f[maxn],g[maxn];
int main()
{
	read(n);
	flg[1]=1;
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		if(i<n)
		{
			char cc;
			scanf("%s",&cc);
			if(cc=='-')
				flg[i+1]=-1;
			else
				flg[i+1]=1;
		}
	}
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]+flg[i]*a[i];
	for(int i=n;i>=1;i--)
		g[i]=g[i+1]+a[i];
	while(l<=n&&flg[l]==1)
		l+=1;
	for(;l<=n;l=r+1)
	{
		long long s=a[l];
		r=l;
		while(r<n&&flg[r+1]==1)
		{
			r+=1;
			s+=a[r];
		}
		ans=max(ans,f[l-1]+g[r+1]-s);
	}
	printf("%lld\n",max(ans,f[n]));
    return 0;
}
