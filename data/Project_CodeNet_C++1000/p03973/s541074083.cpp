#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5;

int n;

int main(){
	scanf("%d",&n);
	ll ans = 0ll;
	ll bef = 1;
	for(int i=1;i<=n;i++){
		ll x;
		scanf("%lld",&x);
		x-=bef;
		if(i==1){
			ans+=x;
		} else if(x<=1){
			bef = max(bef,x+bef);
		} else if(x > 1){
			ans+=(x+bef-1)/(bef+1);
		}
//		cout << ">> " << ans << " <> " << bef << endl;
	}
	printf("%lld\n",ans);
	return 0;
}