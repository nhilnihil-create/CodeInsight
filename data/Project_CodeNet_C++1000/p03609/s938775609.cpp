#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int main(){
	fast;
	ll x,t;
	cin>>x>>t;
	if(x>t)
		cout<<x-t;
	else
		cout<<0;
	return 0;
}

