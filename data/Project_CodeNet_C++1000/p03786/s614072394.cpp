#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll check(vector<ll>&pref, vector<ll>& a){
	ll n=a.size()-1;
	for(int i=n-1;i>=1;i--){
		if(pref[i]*2<a[i+1])
			return i;
	}
	return 0;
}
int main(){
	ll n; cin>>n;
	vector<ll>a(n+1,0);
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a.begin(),a.end());
	vector<ll>pref=a;
	for(ll i=1;i<=n;i++)
		pref[i]=pref[i]+pref[i-1];
	ll x=check(pref,a);
	cout<<n-x<<endl;
	return 0;
}