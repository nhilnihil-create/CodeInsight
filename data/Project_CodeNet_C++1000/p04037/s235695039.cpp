#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 100100
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
int n,a[MAX],ans;
int main()
{
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sort(&a[1],&a[n+1]);reverse(&a[1],&a[n+1]);
	for(int i=1;i<=n;++i)
		if(i+1>a[i+1])
		{
			for(int j=i+1;a[j]==i;++j)ans^=1;
			ans|=(a[i]-i)&1;
			ans?puts("First"):puts("Second");
			return 0;
		}
	return 0;
}
