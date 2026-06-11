#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz size()
#define pb(x) push_back(x) 
#define bg begin()
#define ed end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define mp(x,y) make_pair(x,y)
const ll MOD=1000000007;

ll maxx(ll x,ll y,ll z){
	return max(max(x,y),z);
}
ll minn(ll x,ll y,ll z){
	return min(min(x,y),z);
}
ll gcd(ll x,ll y){
	if(x%y==0) return y;
    else return gcd(y,x%y);
}
ll lcm(ll x,ll y){
	return x*(y/gcd(x,y));
}

//a,b x
int main(){
	ll N,K; cin>>N>>K;
	vector<ll> s(N+1,0);
	vector<ll> abss(N+1,0);
	ll ans=-1000000000000;
	rep(i,N){
		ll A; cin>>A;
		s[i+1]=s[i]+A;
		abss[i+1]=abss[i]+(A>=0?A:0);
	}
	for(int i=K-1;i<=N-1;i++){
		ans=max(ans,max((ll)0,s[i+1]-s[i-K+1])+abss[N]-abss[i+1]+abss[i-K+1]);
	}
	cout<<ans<<endl;
}