/*
                    /\                          _--------- 
				   /  \                       _/
				  /    \                    _/
				 /      \                 _/ 
				/        \               |
		       /          \              | 
		      /------------\             | 
		     /              \            -\
		    /                \             -\
		   /                  \              -\
		  /                    \                -\________
*/
#include<iostream>
#include<cmath>
#include<algorithm>
#pragma GCC diagnostic error "-std=c++11"
#define ll long long
#define mp make_pair
using namespace std;
int n,m;
ll a[100010];
ll t[200010];
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i) scanf("%d",a+i);
	ll sum=0;
	for(i=1;i<n;++i){
		int l=a[i-1],r=a[i];
		if(r<l) r+=m;
		++t[2+l],t[1+r]-=r-l,t[2+r]+=r-l-1;
		sum+=r-l;
	}
	ll ans=sum;
	for(j=2;j--;) for(i=1;i<=m<<1;++i) t[i]+=t[i-1];
	for(i=1;i<=m;++i) if(sum-(t[i]+=t[i+m])<ans) ans=sum-t[i];
	printf("%lld\n",ans);
}