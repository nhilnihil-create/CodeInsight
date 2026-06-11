#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll gcd(ll a,ll b){
	return(a==0)?b:gcd(b%a,a);
}
ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    ll a,ans=1;
    for(int i=0;i<t;++i){
    	cin>>a;
   		ans=lcm(ans,a);
   	}
   	cout<<ans;
   	return 0;
}