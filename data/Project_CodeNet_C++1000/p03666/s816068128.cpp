#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
int n,A,B,C,D;
ll L,R;
void chk(){if(L<=B&&B<=R)puts("YES"),exit(0);}
int main()
{
	n=read();A=read();B=read()-A;C=read();D=read();
	for(int i=0;i<n;++i)
	{
		L=1ll*C*i-1ll*(n-1-i)*D;
		R=1ll*D*i-1ll*(n-1-i)*C;
		chk();
	}
	puts("NO");
	return 0;
}
