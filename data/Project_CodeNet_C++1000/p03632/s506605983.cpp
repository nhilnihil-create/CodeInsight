#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
int main(){
	fast;
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll s=max(a,c),e=min(b,d);
	if(e-s>0)
		cout<<e-s;
	else
		cout<<0;
	return 0;
}

