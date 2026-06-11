#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define ll long long
const ll INF=1000000000000000000;
ll n,cnt,rec,f0,f1=-INF,f2=-INF;
ll read(){ll res;char ch;while(!isdigit(ch=getchar()));res=ch-'0';while(isdigit(ch=getchar()))res=res*10-'0'+ch;return res;}
ll reado(){char ch;while((ch=getchar())!='+'&&ch!='-');return ch=='-';}
int main()
{
	n=read();
	for(ll i=1,a,o=0;i<=n;++i)
	{
		if(i>1)o=reado();
		a=read();
		if(o)f0=f1=max(f0-a,f2=f1+a);
		else f0+=a,f1=max(f1-a,f2+=a);
	}
	printf("%lld",f0);
	return 0;
}