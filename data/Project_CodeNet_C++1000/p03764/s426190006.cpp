#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define mod 1000000007
#define LL long long
using namespace std;
int n,m;
LL x[100005];
LL y[100005];

int main()
{
	IO
	cin>>n>>m;
	
	for(int i = 0; i < n; ++i){
		cin>>x[i];
		x[i] += 1000000000;
	}
	for(int i = 0; i < m; ++i){
		cin>>y[i];
		y[i] += 1000000000;
	}
	LL base = 0;
	LL height = 0;
	for(int i = 1; i < n; ++i){
		LL d = x[i]-x[i-1];
		base = (base + ((d*((LL)(n-i)))%mod + (((d*(LL)(n-i))%mod)*(LL)(i-1))%mod)%mod)%mod;
	}
	for(int i = 1; i < m; ++i){
		LL d = y[i]-y[i-1];
		height = (height + ((d*((LL)(m-i)))%mod + (((d*(LL)(m-i))%mod)*(LL)(i-1))%mod)%mod)%mod;
	}
	cout<<((base*height)%mod)<<endl;

	return 0;
}