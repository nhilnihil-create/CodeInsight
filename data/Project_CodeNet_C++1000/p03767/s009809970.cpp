#include<bits/stdc++.h>
#define ll long long int
#define l(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
int main(){
	ll k;
	cin>>k;
	ll n = 3*k;
	ll a[n];
	l(i,0,n) cin>>a[i];
	sort(a,a+n);
	ll i=n-2;
	ll num = 0,sum = 0;
	while(num<k){
		sum+=a[i];
		i-=2;
		num++;
	}	
	cout<<sum<<"\n";
}