#include<iostream>
#include<cstdio>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,a[MN+5];
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int t=1;;t^=1)
	{
		int evennum=0,oddnum=0,odd=0;
		for(int j=1;j<=n;++j) 
			if(a[j]&1) ++oddnum,odd=a[j];
			else ++evennum;
		if(evennum&1) return 0*puts(t?"First":"Second");
		else if(oddnum==1&&odd>1)
		{
			int g=0;
			for(int j=1;j<=n;++j) 
			{
				if(a[j]&1) --a[j];
				g=gcd(a[j],g);
			}
			for(int j=1;j<=n;++j) a[j]/=g;
		}
		else return 0*puts(t?"Second":"First");
	}
	return 0;
}
