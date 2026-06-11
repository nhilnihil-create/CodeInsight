#include <bits/stdc++.h>
using namespace std;
//mt19937 mrand(chrono::high_resolution_clock::now().time_since_epoch().count());
//int rnd(int x) { return mrand()%x;}
typedef long long ll;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
int main(){
	ll n,x;
	scanf("%lld%lld",&n,&x);
	ll ans=n;
	ll a=x,b=n-x;
	while(a && b){
		if(a>b) swap(a,b);
		ans+=b/a*a*2;
		b=b%a;
		if(b==0) ans-=a;
	}
	printf("%lld\n",ans);
	return 0;
}
