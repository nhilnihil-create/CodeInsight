#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const p=31,mod=1e9+9;
ll pw[300];
ll sq(ll a){
	return (a*a)%mod;
}
ll exp(ll a,ll b){
	if(b==0)return 1;
	if(b==1)return a;
	if(b&1){
		return (a*sq(exp(a,b>>1)))%mod;
	}
	return sq(exp(a,b>>1))%mod;
}
ll inv(ll a){
	return exp(a,mod-2);
}
int main(){
	string s;cin>>s;
	pw[0]=1;
	ll hash[300];
	hash[0]=0;
	for(int i=1;i<=200;i++){
		pw[i]=pw[i-1]*p;
		pw[i]%=mod;
	}
	for(int i=1;i<=s.size();i++){
		hash[i]=(hash[i-1]+s[i-1]*pw[i])%mod;
	}
	for(int i=s.size()-3;i>0;i-=2){
		// cout<<(i+1)<<' '<<(((hash[i+1]-hash[(i+1)/2]+mod)%mod)*inv(pw[(i+1)/2]))%mod<<endl;
		// cout<<(i+1)/2<<' '<<hash[(i+1)/2]<<endl;
		if(hash[(i+1)/2]==(((hash[i+1]-hash[(i+1)/2]+mod)%mod)*inv(pw[(i+1)/2]))%mod){
			cout<<i+1;return 0;
		}
	}
}