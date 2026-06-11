// Do you knOW what it feels like?

		// To be TorTured by your own MinD?
	
	// I don't wanna feel the PAIN.

// I BeG you to KILL me, pleASE...

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Os")

#define F first
#define S second
#define pb push_back
#define SZ(x) (ll)(x.size())
#define all(x) x.begin(),x.end()

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=5e2+10, lg=22, mod=1e9+7, inf=1e18;

ll n,ans[maxn*maxn],a[maxn],f[maxn];
bool cmp(int x,int y){return a[x]<a[y];}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=i;
	}
	sort(f+1,f+n+1,cmp);
	ll k=1;
	for(int i=1;i<=n;i++){
		ans[a[f[i]]]=f[i];
		for(int j=1;j<f[i];j++){
			while(ans[k]) k++;
			if(k>a[f[i]]) return cout<<"No", 0;
			ans[k]=f[i];
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-f[i];j++){
			while(ans[k]) k++;
			if(k<a[f[i]]) return cout<<"No", 0;
			ans[k]=f[i];
		}
	cout<<"Yes"<<endl;
	for(int i=1;i<=n*n;i++) cout<<ans[i]<<' ';
	return 0;
}
















