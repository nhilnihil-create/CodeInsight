/*
   Author : tarang
*/
#include<bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with(false); cin.tie(0);cout.tie(0);
const int MOD = 1000000007;
#define PI = acos(-1)
using namespace std ;
ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
int main(){
	ll n , k ;
	cin >> n >> k ;
	ll x = pow(k-1 , n-1);
	x*=k;
	cout << x << endl;
}

