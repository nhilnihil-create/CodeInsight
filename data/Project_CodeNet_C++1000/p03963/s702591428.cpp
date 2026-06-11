#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);i++)
ll pow(ll a,ll b){
	if(b==0) return 1;
	if(b==1) return a;
	ll x=pow(a,b/2);
	if(b&1) return x*x*a;
	return x*x;
}
int main(){
	ll n,k; cin>>n>>k;
	cout<<k*pow(k-1,n-1);
}
