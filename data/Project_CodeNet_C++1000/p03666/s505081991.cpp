#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	n--;
	bool ans=false;
	for(ll i=0;i<n;i++){
		ll l=a+i*c-(n-i)*d;
		ll r=a+i*d-(n-i)*c;
		if(l<=b&&b<=r){
			ans=true;
		}
	}
	cout << (ans?"YES":"NO");
	return 0;
}