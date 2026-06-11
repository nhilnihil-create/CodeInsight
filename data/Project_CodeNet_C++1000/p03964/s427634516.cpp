#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
const ll mx=1e18+7;
 
int main() {
	int n;
	cin>>n;
	ll a, b;
	cin>>a>>b;
	n--;
	while(n--){
		ll x, y, k1=mx, k2=mx;
		cin>>x>>y;
		if( x >= a && y >= b) 
		{
			a=x;
			b=y;
			continue;
		}
	    if( x < a ) {
			k1=(a+x-1LL)/x;
			if(y*k1<b) k1= mx;
		}
		if( y < b ) {
			k2=(b+y-1LL)/y;
			if(x*k2<a) k2= mx;
		}
		a=x*min(k1,k2);
		b=y*min(k1,k2);				
		}
		
	cout<<a+b<<endl;	
	return 0;
}