#include<bits/stdc++.h>
using namespace std;


typedef long long int ll;

int main()
{
	ll n;
	cin>>n;
	ll ret=0;
	ll pre=0;
	
	for(ll i=0; i<n; i++) {
		ll x;
        cin>>x;
		if(pre==0) {
			ret += x-1;
			pre=1;
		}
		else if(x==pre+1) {
			pre++;
		}
		else if(x>pre+1) {
			ret += (x-1)/(pre+1);
		}
	}
	cout<<ret<<endl;
}
