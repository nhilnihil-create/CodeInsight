#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	ll n;cin>>n;
	ll a,b;cin>>a>>b;
	vector<ll> d(n);

	for(int i = 0; i < n; i++) {
		cin>>d[i];
	}
	ll ans = 0;
	for(int i = 0; i < n - 1; i++) {
		ll x = d[i + 1] - d[i];
		x *= a;
		ans += min(x,b);
	}
	cout << ans << endl;
	return 0;
}