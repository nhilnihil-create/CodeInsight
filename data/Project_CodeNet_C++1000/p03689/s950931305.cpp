#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 555
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
int H,W,h,w;
int a[MAX][MAX];
long long sum=0;
int main()
{
	H=read();W=read();h=read();w=read();
	for(int i=1;i<=H;++i)
		for(int j=1;j<=W;++j)
			a[i][j]=1000;
	for(int i=h;i<=H;i+=h)
		for(int j=w;j<=W;j+=w)
			a[i][j]=-h*w*1000+999;
	for(int i=1;i<=H;++i)
		for(int j=1;j<=W;++j)sum+=a[i][j];
	if(sum<0)puts("No");
	else
	{
		puts("Yes");
		for(int i=1;i<=H;++i,puts(""))
			for(int j=1;j<=W;++j)
				printf("%d ",a[i][j]);
	}
	return 0;
}
