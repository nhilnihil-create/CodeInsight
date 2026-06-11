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
const ll INF=1<<30;

// [1, n]
ll n;
vector<ll> a;

int main(){
	cin>>n;
	vector<ll> alt;
	for(int i = 0; i < n; i++) {
		ll x;cin>>x;
		a.pb(x);
		alt.pb(x);
	}
	sort(ALL(alt));
	for(int i = 0; i < n; i++) {
		int it = lower_bound(ALL(alt),a[i]) - alt.begin();
		a[i] = it;
	}
	int ans = 0;
	for(int i = 0; i < n; i+= 2) {
		if(a[i] % 2 != 0){
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}