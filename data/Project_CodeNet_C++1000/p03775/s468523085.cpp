#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
map<ll,int>mp;
int f(ll n){
	int x=0;
	while(n){
		x++,n/=10;
	}
	return x;
}
int main(){
	ll n,m;
	cin>>n;
	ll ans=1e9;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			ll x=max(f(i),f(n/i));
			ans=min(ans,x);
		}
	}
	cout<<ans;
	return 0;
}