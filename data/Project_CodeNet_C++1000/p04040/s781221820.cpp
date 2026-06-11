#include <iostream>
//#include <bits/stdc++.h>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pb(x) push_back(x)
#define F first
#define S second
using namespace std;
using ll = long long;
const int MOD=1e9+7;
const int MAXN=1e6+5;

ll modpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=(res*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return res;
}
ll f[MAXN];
ll invf[MAXN];

ll ncr(ll n,ll r){
	if(r==0 || n==r) return 1;
	return (((f[n]*invf[n-r])%MOD)*invf[r])%MOD;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int h,w,a,b;
	cin>>h>>w>>a>>b;
	f[0]=1;
	for(int i=1;i<MAXN;i++){
		f[i]=(f[i-1]*i)%MOD;
		invf[i]=modpow(f[i],MOD-2);
	}
//	
//	ll res=0;
//	for(int i=b;i<w;i++){
//		int y1=h-a-1,x1=i;
//		int y2=a-1, x2=w-i-1;
//		ll p=(ncr(x1+y1,x1)*ncr(x2+y2,x2))%MOD;
//		res=(res+p)%MOD;
//	}
	ll ans=0;
	for(int i=b;i<w;i++){
		ll ways=(ncr(h-a-1+i,i)*ncr(w-i-1+a-1,w-i-1))%MOD;
		ans=(ans+ways)%MOD;
	}
	cout<<ans<<'\n';
	return 0;
}

