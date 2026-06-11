#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store")  
#pragma GCC optimize ("-fno-defer-pop")
#define all(a) a.begin(),a.end()
#define bs binary_search
#define ll long long int
#define ld long double
ll power(ll a,ll b,ll m){ if(b==0) return 1; if(b==1) return a%m; ll t=power(a,b/2,m)%m; t=(t*t)%m; if(b&1) t=((t%m)*(a%m))%m; return t;}
ll modInverse(ll a, ll m) { return power(a, m-2, m); }
#define ipr pair<ll,ll>
#define ps push_back
#define fs first
#define sc second
#define mkp make_pair
#define mod 1000000007
int main(){
	
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll i,j,k,l,r,n,a,b,m;
	cin>>n>>a>>b;
	ll h[n],s=0;
	for(i=0;i<n;i++){
		cin>>h[i];
		if(h[i]>s){
			s=h[i];
		}
	}
	l=1; r=s/b+1;

	ll an=-1;
	while(r>=l){
		//cout<<l<<" "<<r<<endl;
		m=(r+l)/2;
		ll c=0;
		for(i=0;i<n;i++){
			k=max((ll)0,(h[i]-m*b));
			if(k%(a-b)==0) c+=(k/(a-b));
			else c+=(k/(a-b)+1);
		}
		if(c<=m){
			an=m;
			r=m-1;
		}
		else l=m+1;
	}
	cout<<an;
	return 0;
}
