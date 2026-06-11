#include <bits/stdc++.h>
using namespace std;\

typedef long long ll;
const ll INF=1000000000000000;

#define chmin(a,b) a=min(a,b)

int main(){
	static ll n;
	static ll a[200010];
	scanf("%lld",&n);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	
	ll sum=0;
	for(int i=0;i<n;i++)sum+=a[i];
	ll ret=INF;
	ll s=0;
	for(int i=0;i<n-1;i++){
		s+=a[i];
		chmin(ret,abs(sum-s-s));
	}
	cout<<ret<<endl;
}

