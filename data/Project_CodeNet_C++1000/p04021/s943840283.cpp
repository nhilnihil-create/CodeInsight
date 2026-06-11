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

const ll maxn=1e5+10, mod=1e9+7, inf=1e18;

ll n,a[maxn],b[maxn];
map<ll,ll> wer;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin>>n;
	ll tom=0;
	for(int i=0;i<n;i++){ cin>>a[i]; b[i]=a[i]; }
	sort(a,a+n);
	for(int i=0;i<n;i++) wer[a[i]]=i;
	for(int i=0;i<n;i++) tom+=(wer[b[i]]+i)%2;
	cout<<tom/2;

	return 0;
}











