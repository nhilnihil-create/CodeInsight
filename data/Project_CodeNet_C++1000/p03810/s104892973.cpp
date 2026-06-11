#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read()
{
	int k=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) k=k*10+c-'0';return f*k;
}
const int N=100055;
int n,a[N];
int gcd(int a,int b)
{	
	if(!b) return a;
	return gcd(b,a%b);
}
int sol()
{
	int cnt=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)
		{
			int S=0;
			for(int j=1;j<=n;j++)
				S=(S+a[j]-1)&1;
			return S;
		}
		if(a[i]&1) cnt++;
		else sum++;
	}
	if(sum&1) return 1;
	if(cnt>1) return 0;
	int now=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]&1) a[i]--;
		if(!now) now=a[i];
		else now=gcd(now,a[i]);
	}
	for(int i=1;i<=n;i++)
		a[i]/=now;
	return sol()^1;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	if(sol()) puts("First");
	else puts("Second");
	return 0;
}
