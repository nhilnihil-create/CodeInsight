#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const ll MOD = 1000000007;
const ll INF = 1e18;
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

int main(){
	int n; cin >> n;
	VI a(n); REP(i,n) cin >> a[i];
	ll ans=a[0]-1, p=2;
	for(int i=1;i<n;i++){
		if(a[i]==p)
			p++;
		ans+=(a[i]-1)/p;
	}
	cout << ans << endl;
	return 0;
}