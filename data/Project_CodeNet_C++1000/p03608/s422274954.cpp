#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store") // to restrict undesirable precision
#pragma GCC optimize ("-fno-defer-pop")// to pop argument of function as soon as it returns
#define all(a) a.begin(),a.end()
#define ll long long int
#define ld long double
ll power(ll a,ll b,ll m){ if(b==0) return 1; if(b==1) return a%m; ll t=power(a,b/2,m)%m; t=(t*t)%m; if(b&1) t=((t%m)*(a%m))%m; return t;}
ll modInverse(ll a, ll m) { return power(a, m-2, m); }
#define ps push_back
#define fs first
#define sc second
#define takeline cin.ignore();
#define iactive cout.flush();
#define N 205
#define endl "\n"
#define mod 1000000007
//((1.0l)*BIG MULTIPLY MAGIC?)
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
//------------------------------------
ll n,m,r;
int main(){
	
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll i,j,k,l;
	cin>>n>>m>>r;
	ll cst[n+1][n+1];
	vector<ll> v;
	for(i=1;i<=r;i++){
		cin>>k;
		v.ps(k);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cst[i][j]=2e18;
		}
	}
	ll a,b,c;
	for(i=1;i<=m;i++){
		cin>>a>>b>>c;
		cst[a][b]=c;
		cst[b][a]=c;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				cst[j][k]=min(cst[j][k],cst[j][i]+cst[i][k]);
			}
		}
	}
	ll mn=2e18; sort(all(v));
	do{
		ll c=0;
		for(i=1;i<r;i++){
			c+=cst[v[i-1]][v[i]];
		}
		mn=min(mn,c);
	}while(next_permutation(all(v)));
	cout<<mn;
	return 0;
}