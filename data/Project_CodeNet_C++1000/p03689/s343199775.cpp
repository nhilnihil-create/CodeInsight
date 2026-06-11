#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define si scanf
#define so printf
#define N 
#define M 
#define INF  
template<typename TP>inline bool rd(TP& r)
{
	r=0;
	char tmp=getchar();
	while(tmp<'0'||tmp>'9')
	{
		if(tmp==EOF)
			return 0;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		r=(r<<3)+(r<<1)+tmp-'0';
		tmp=getchar();
	}
	return 1;
	
} 
int H,h,W,w;
long long pos,neg,sm;
long long mat[510][510];
int main()
{
	rd(H),rd(W),rd(h),rd(w);
	if(W%w==0&&H%h==0)
	{
		so("No\n");
		return 0;
	}
	pos=(1000000000-1)/(1LL*w*h-1);
	neg=-(pos*(1LL*w*h-1)+1);
	for(int i=1;i<=H;++i)
	for(int j=1;j<=W;++j)
		if(i%h==0&&j%w==0)
			mat[i][j]=neg,sm+=neg;
		else
			mat[i][j]=pos,sm+=pos;
	if(sm<=0)
		so("No\n");
	else
	{
		so("Yes\n");
		for(int i=1;i<=H;++i)
		{
			for(int j=1;j<=W;++j)
				so("%lld ",mat[i][j]);
			so("\n");
		}
	}
	return 0;
} 