#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
ll dp[5005][5005], n, x;
string soal;

ll pgt(ll x, ll p){
	if(p==0) return 1;
	if(p==1) return x;
	ll a= pgt(x, p/2);
	if(p%2==1) return (((a*a)%MOD)*x)%MOD;
	return (a*a)%MOD;
}

ll f(ll l, ll step){
	if(step==0){
		if(l==x) return 1;
		else return 0;
	}
	
	ll &ret = dp[l][step];
	
	if(ret==-1){
		ret=(2*f(l+1, step-1))%MOD;
		if(l==0) ret=(ret+f(l, step-1))%MOD;
		else	 ret=(ret+f(l-1, step-1))%MOD;
	}
	
	return ret; 
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(dp, -1, sizeof(dp));
	cin>>n;
	cin>>soal;
	x=soal.length();
	cout<<(f(0, n)*pgt(pgt(2, x), MOD-2))%MOD<<"\n";
}