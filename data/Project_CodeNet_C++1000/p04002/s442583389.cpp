#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int>a;
pair <int,int> hh;
int h,m,w,x,y;
long long c[10];
int main()
{
	scanf("%d%d%d",&h,&m,&w);
	c[0]=1ll*(h-2)*(m-2);
	for (int i=1;i<=w;++i)
	  {
	  	scanf("%d%d",&x,&y);
	  	for (int j=max(3,x);j<=min(x+2,h);++j) for (int k=max(3,y);k<=min(y+2,m);++k) c[a[make_pair(j,k)]]--,c[++a[make_pair(j,k)]]++;
	  }
	for (int i=0;i<=9;++i) printf("%lld\n",c[i]);
	return 0;
}