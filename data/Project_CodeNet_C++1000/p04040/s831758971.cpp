#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int md=1e9+7;
int qmul(int x,int p)
{
	int res=1;
	for(;p;p>>=1,x=1LL*x*x%md)if(p&1)res=1LL*res*x%md;
	return res;
}
int fac[200010],inv[200010];
inline int C(int x,int y){return 1LL*fac[x]*inv[x-y]%md*inv[y]%md;}
int h,w,a,b;
int main()
{
	fac[0]=1;
	for(int i=1;i<=200000;i++)fac[i]=1LL*fac[i-1]*i%md;
	inv[200000]=qmul(fac[200000],md-2);
	for(int i=199999;i>=0;i--)inv[i]=1LL*inv[i+1]*(i+1)%md;
	scanf("%d%d%d%d",&h,&w,&a,&b);
	int ans=C(h+w-2,h-1);
	int x=h-a+1,y=b;
	while(x<=h && y)
	{
		ans=(ans+md-1LL*C(x+y-2,x-1)*C(h+w-x-y,h-x)%md)%md;
		x++;y--;
	}
	printf("%d",ans);
	return 0;
}