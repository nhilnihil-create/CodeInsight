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
int n,L,T,t;
int pos[MAX];
int main()
{
	n=read();L=read();T=read();
	for(int i=0;i<n;++i)
	{
		int x=read(),w=(read()==2)?-1:1;
		pos[i]=((x+w*T)%L+L)%L;
		if(~w)t=(t+(x+T)/L)%n;
		else t=(t+(x-T)/L-(((x-T)%L<0)?1:0)+n)%n;
	}
	sort(&pos[0],&pos[n]);
	for(int i=t;i<n;++i)printf("%d\n",pos[i]);
	for(int i=0;i<t;++i)printf("%d\n",pos[i]);
	return 0;
}
