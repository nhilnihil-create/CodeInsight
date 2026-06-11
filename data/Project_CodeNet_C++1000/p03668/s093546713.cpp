#ifndef KHOKHO
//#pragma GCC optimize("O3")
#endif
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
//#define CHKR
#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define ARRS int(1e6+500)
#define MAX ((long long)(1e18+1))
#define EP ((double)(1e-12))
#define HS1 ((ll)(1000001329))
#define HS2 ((ll)(1000001531))
#define MOD ((long long)1000000007ll)
#define AT9 ((long long)1000000000ll)
#define PI 3.14159265358979323846264338327950288419716939937510
#define LG 20

vector<ll> v[ARRS];
ll dp[ARRS];

void go(ll x,ll p){

	set<ll> st;
	ll xr=0;
	for(auto y:v[x]){
		if(y==p)continue;
        go(y,x);
        xr^=(dp[y]+1);
	}
	dp[x]=xr;
	//cout<<x<<" "<<dp[x]<<endl;
}

int main(){
	#ifdef KHOKHO
		freopen("in.in","r",stdin);
		freopen("out.out","w+",stdout);
	#endif //KHOKHO
	ll n,a,k,p,b,c,d;
	cin>>n;
	for(int i=0; i<n-1; i++){
		cin>>k>>p;
		v[k].pb(p);
		v[p].pb(k);
	}
	go(1,-1);
	if(dp[1]){
		cout<<"Alice";
	}
	else cout<<"Bob";
	return 0;
}
