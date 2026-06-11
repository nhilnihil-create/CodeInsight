#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
	if(a%b==0)return ((a/b)*2-1)*b;
	return gcd(b,a%b)+((a/b)*2)*b;
}
int main(){
	ll n,x;
	cin>>n>>x;
	if(x<n-x)x=n-x;
	cout<<gcd(x,n-x)+n;
	return 0;
}