#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define SF scanf
#define PF printf
#define MAXN 100010
using namespace std;
typedef long long ll;
ll n,d,t;
ll dir[MAXN],pos[MAXN];
ll a[MAXN],b[MAXN],cnta,cntb;
ll find1(ll l,ll r){
	return upper_bound(b+1,b+1+cntb,r)-lower_bound(b+1,b+1+cntb,l);	
}
ll find2(ll l,ll r){
	return upper_bound(a+1,a+1+cnta,r)-lower_bound(a+1,a+1+cnta,l);	
}
ll ans[MAXN];
int main(){
	SF("%lld%lld%lld",&n,&d,&t);
	t*=2ll;
	for(int i=1;i<=n;i++){
		SF("%lld%lld",&pos[i],&dir[i]);
		if(dir[i]==1)
			a[++cnta]=pos[i];
		else
			b[++cntb]=pos[i];
	}
	ll t1=t/d;
	ll t2=t%d;
	for(int i=1;i<=n;i++){
		if(dir[i]==1){
			ll cnt=t1*cntb;
			ll l=pos[i];
			ll r=(pos[i]+t2)%d;
			if(r<l)
				cnt+=find1(l,d-1)+find1(0,r);
			else
				cnt+=find1(l,r);
			ans[(i+cnt-1)%n+1]=(pos[i]+t/2ll)%d;
		}
		else{
			ll cnt=t1*cnta;
			ll r=pos[i];
			ll l=(pos[i]-t2+d)%d;
			if(r<l)
				cnt+=find2(l,d-1)+find2(0,r);
			else
				cnt+=find2(l,r);
			ans[((i-cnt)%n+n-1)%n+1]=((pos[i]-t/2ll)%d+d)%d;
		}
	}
	for(int i=1;i<=n;i++)
		PF("%lld\n",ans[i]);
}