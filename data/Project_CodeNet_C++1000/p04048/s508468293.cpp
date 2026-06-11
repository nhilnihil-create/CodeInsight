// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
 
using namespace std;
 
typedef long long LL;
 
const int inf = 1 << 30;
LL ans=0;
 
LL gd(LL x,LL y){
//	if(x==1 && y==1)return 2333;
	if(!y)return ans-=x,x;
	if(x<y)swap(x,y);
	ans+=x/y*y*2;
//	printf("%lld %lld %lld  %lld\n",x,y,ans,x/y*y*2);
	return gd(y,x%y);
}
 
int main(){
	LL n,x;cin>>n>>x;
	ans=n;
	gd(max(n-x,x),min(n-x,x));
	printf("%lld\n",ans);
 
	return 0;
}