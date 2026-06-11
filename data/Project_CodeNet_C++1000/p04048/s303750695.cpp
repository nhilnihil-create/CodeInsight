#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n,x;
	scanf("%lld %lld",&n,&x);
	ll ans=n;
	ll a=x,b=n-x;
	while(1){
		if(a>b)swap(a,b);
		if(b%a==0){ans+=b*2-a;break;}
		ans+=2*(b-(b%a));
		b%=a;
	}
	printf("%lld\n",ans);
	return 0;
}