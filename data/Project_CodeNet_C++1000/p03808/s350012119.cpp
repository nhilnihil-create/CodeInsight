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
	
	ll i,j,k,l,n;
	cin>>n;
	ll ar[n],s=0;
	for(i=0;i<n;i++){
		cin>>ar[i];
		s+=ar[i];
	}
	
	k=(n*(n+1))/2;
	if(s%k==0){
		int f=1;
		k=(s/k);
		for(i=1;i<n;i++){
			l=(ar[i]-ar[i-1])-k;
			if(l>0) {
				f=0;
				break;
			}
			if(l<0) l=-l;
			if(l%n!=0){
				//cout<<"@";
				f=0;
				break;
			}
		}
		l=ar[0]-ar[n-1]-k;
		if(l>0) {
			f=0;
		}
		if(l<0) l=-l;
		if(l%n!=0){
			//cout<<"$";
			f=0;
		}
		if(f==1){
			cout<<"YES";
		}
		else {
			cout<<"NO";
		}
	}
	else {
		cout<<"NO";
	}
	return 0;
}
