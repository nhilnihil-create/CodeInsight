#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
ll ksm(ll a,ll n){
	ll ans=1;
	while(n){
		if(n&1) ans=ans*a%mod;
		a=a*a%mod;
		n>>=1;
	}
	return ans;
}
int main(){
	ll n,m;cin>>n>>m;
	if(n>m) swap(n,m);
	if(n<m-1) puts("0");
	else if(n==m){
		ll s=1;
		for(int i=1;i<=n;i++) s=s*i%mod;
		cout<<s*s*2%mod<<endl; 
	}
	else {
	ll x=1,y=1,s=1;
	for(int i=1;i<=m;i++){
		s=s*i%mod;
		if(i==m-1-n) x=s;
		else if(i==m-1) y=s;
	}
	x=ksm(x,mod-2);
	y=y*x%mod;
	s=y*s%mod;
	cout<<s<<endl;
	}
	return 0;
}