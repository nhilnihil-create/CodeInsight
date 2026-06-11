#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(long long (i)=0;(i)<(n);++(i))
#define ref(i,a,b) for (long long (i)=(a); (i)<=(b); ++(i))
#define INF 0xFFFFFF
#define endl '\n'
#define pb push_back
#define mp make_pair
const unsigned int mod = 1e9+7;
const int mx=1e5+5;
long long v[mx];
ll n,a,b;
bool ok(ll k){
	ll cnt=0;
	for(int i=0;i<n;++i){
		ll now=max(0LL,v[i]-b*k);//now=
		cnt+=(now+a-1)/a;
	}
	return cnt<=k;
}	
int main(){
	/*freopen(".gir", "r", stdin);
	freopen(".cik", "w", stdout); 
    */ios_base::sync_with_stdio(false);cin.tie(NULL);
	cin >> n >> a >> b ;
	rep(i,n)cin >> v[i];
	a-=b;
	ll l=-1;
	ll r=1000000009;
	while(r-l>1){
		ll m=(l+r)/2;
		if(ok(m))r=m;
		else l=m;
	}
	cout << r << endl;
}
	