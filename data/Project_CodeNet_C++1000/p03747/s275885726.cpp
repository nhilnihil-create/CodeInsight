#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,L,T;
struct evol{long long x,w;}a[101010];
bool cmp(evol u,evol v){return u.x<v.x;}
int main()
{
	scanf("%d%d%d",&n,&L,&T);
	for(int i=1,x,y;i<=n;i++)
	scanf("%lld%lld",&a[i].x,&a[i].w);
	long long rk=0;	
	for(int i=1;i<=n;i++)
	{
		if(a[i].w==1) a[i].x+=T;
		else a[i].x-=T;
		rk+=a[i].x/L;
		if(a[i].x%L<0) rk--;
		a[i].x=(a[i].x%L+L)%L;
	}
	sort(a+1,a+n+1,cmp);
	rk=(rk%n+n)%n;
	for(int i=rk+1;i<=n;i++)
	printf("%lld\n",a[i].x);
	for(int i=1;i<=rk;i++)
	printf("%lld\n",a[i].x);
	return 0;
}