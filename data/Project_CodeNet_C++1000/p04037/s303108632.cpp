#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;
char buf[1<<20],*p1,*p2;
#define GC (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?0:*p1++)
inline ll R()
{
	char t=GC;
	ll x=0;
	while(!isdigit(t))t=GC;
	while(isdigit(t))x=x*10+t-48,t=GC;
	return x;
}
int n,a[1000005];
inline bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int t=0;
	n=R();
	for(register int i=1; i<=n; i++)
		a[i]=R();
	sort(a+1,a+n+1,cmp);
	for(register int i=1; i<=n; i++)
		if(i+1>a[i+1])
		{
			while(a[t+i+1]==i)
				t++;
			if(((a[i]-i)&1)||(t&1))
				puts("First");
			else
				puts("Second");
			break;
		}
	return 0;
}
