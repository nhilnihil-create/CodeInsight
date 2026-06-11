#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
int n,a[100100];
void WA(){puts("No");exit(0);}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sort(&a[1],&a[n+1]);
	if(abs(a[n]-a[1])>1){puts("No");return 0;}
	if(a[n]==a[1])
	{
		if(a[n]==1||a[n]==n-1||2*a[n]<=n)puts("Yes");
		else puts("No");
		return 0;
	}
	int cnt=0;
	for(int i=n;i;--i)if(a[i]==a[n])++cnt;
	int v=a[n]-(n-cnt);
	if(v>0&&2*v<=cnt&&a[1]==v+(n-cnt)-1)puts("Yes");
	else puts("No");
	return 0;
}
