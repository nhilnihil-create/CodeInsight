#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=1e6+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a) memset(a,0,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first 
#define se second
ll ksm(ll a,ll n){
	ll ans=1;
	while(n){
		if(n&1) ans=ans*a;
		a=a*a;
		n>>=1;
	} 
	return ans;
}
int main(){
	int n;
	ll x,y;
	scanf("%d%lld%lld",&n,&x,&y);
	for(int i=2;i<=n;i++){
		 ll a,b,c=0,d=0;
		 scanf("%lld%lld",&a,&b);
		 if(a>=x&&b>=y) {
		 	x=a,y=b;
		 	continue;
		 }
		 if(a<x){
		 	c=(x+a-1)/a;
		 }
		 if(b<y){
		 	d=(y+b-1)/b;
		 }
		 ll mx=max(c,d);
		 x=a*mx,y=b*mx; 
		 //printf("x=%lld,y=%lld\n",x,y);
	}
	printf("%lld\n",x+y);
	return 0;
}