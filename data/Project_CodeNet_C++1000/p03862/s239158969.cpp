#include<bits/stdc++.h>
#define ll long long int 
#define w(x) int x; cin>>x; while(x--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
int main(){
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n,x;
	cin>>n>>x;
	ll a[n];
	for(ll i=0; i<n; i++)
		cin>>a[i];
	ll ans=0,z;
	for(ll i=0; i<n-1; i++){
		if(a[i]+a[i+1]>x){
			if(a[i]+a[i+1]-x>=a[i+1]){
				ans+=a[i]+a[i+1]-x;
				a[i+1]=0;
			}
			else{
				ans+=a[i]+a[i+1]-x;
				z=a[i]+a[i+1]-x;
				a[i+1]-=z;
			}
		}
	}
	cout<<ans;

}