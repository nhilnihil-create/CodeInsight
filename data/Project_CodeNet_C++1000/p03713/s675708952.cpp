#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
ll fun(ll s,ll x,ll y){
	ll a=x>>1,b=y>>1;
	ll t1[3],t2[3];
	t1[0]=abs(a*y-s),t1[1]=abs((x-a)*y-s),t1[2]=abs(a*y-(x-a)*y);
	sort(t1,t1+3);
	ll ans=t1[2];
	t2[0]=abs(b*x-s),t2[1]=abs((y-b)*x-s),t2[2]=abs(b*x-(y-b)*x);
	sort(t2,t2+3);
	return min(ans,t2[2]);
}
int main(){
	ll h,w;cin>>h>>w;
	ll s=h*w;
	if(s%3==0)  puts("0");
	else {
		ll ans=1e15;
		for(int i=1;i<h;i++){
			ans=min(ans,fun(i*w,h-i,w));
		}
		for(int i=1;i<w;i++){
			ans=min(ans,fun(i*h,w-i,h));
		}
		cout<<ans<<endl;
	}
	return 0;
}