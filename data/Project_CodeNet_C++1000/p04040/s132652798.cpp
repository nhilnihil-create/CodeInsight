#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll n, m, a, b, s;
ll f[1000005];
pair<ll,ll> exgcd(ll a, ll b){
	if(b==0) return {1, 0};
	auto p=exgcd(b, a%b);
	return {p.second, p.first-a/b*p.second};
}
ll inv(ll x){
	auto p=exgcd(x, mod);
	return (p.first%mod+mod)%mod;
}
ll C(ll p, ll q){
	return f[p]*inv(f[q])%mod*inv(f[p-q])%mod;
}
int main(){
	cin>>n>>m>>a>>b;
	f[0]=1;
	for(int i=1;i<=m+n;i++) f[i]=(f[i-1]*i)%mod;
	for(ll i=0;i<=n-a-1;i++){
		s+=C(i+b-1, b-1)*C(m+n-b-i-2, m-b-1)%mod;
		s=s%mod;
	}
	cout<<s;
	//i, b
	//i+b-1, b-1
	//n-i-1, m-b
	//m+n-b-i-2, m-b-1
}