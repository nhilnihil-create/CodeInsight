#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,a,b,lst,ans,x;
inline LL mn(LL k,LL l){return k<l?k:l;}
int main(){
	scanf("%lld%lld%lld%lld",&n,&a,&b,&lst);
	for(--n;n--;){
		scanf("%lld",&x);
		ans+=mn(b,a*(x-lst));lst=x;
	}printf("%lld\n",ans);return 0;
}