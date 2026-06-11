#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define MOD (ll)(1e9+7)
#define INF 1e17
#define int ll
#define EPS (1e-6)
using namespace std;
using ll=long long;
using pii=pair<int,int>;

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }

int fpow(int b,int p)
{
	if(p==0) return 1;
	int h=fpow(b,p/2);
	if(p%2) return h*b%MOD*h%MOD;
	return h*h%MOD;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,k; cin>>n>>k;
	vector<int> v(n);
	for(auto &i:v) cin>>i;
	int now=0;
	For(i,0,k-1) now+=v[i];
	int tot=0;
	For(i,k,n-1) tot+=max(0ll,v[i]);
	int ans=tot+max(0ll,now);
	//cout<<tot<<" "<<now<<"\n";
	For(i,k,n-1){
		//cout<<tot<<" "<<now<<"\n";
		now+=v[i]-v[i-k];
		tot+=max(0ll,v[i-k])-max(0ll,v[i]);
		ans=max(ans,tot+max(0ll,now));
	}
	cout<<ans<<"\n";
	return 0;
}



























