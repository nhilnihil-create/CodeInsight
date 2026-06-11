#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define FOR(i, a, b) for(ll i = (ll)a; i <= (ll)b; i++)
#define DEC(i, a, b) for(ll i = (ll)a; i >= (ll)b; i--)
typedef pair<ll, ll> pi;
#define f first
#define s second
#define pb push_back
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

ll n, k, a, ss[200005], sum, ans;
vector<ll> v;
ll ft[200005];              // 1-index
ll ls(ll x){
	return (x & (-x));
}
// N means the largest possible index you need for the fenwick!! Refer to flowering for more.
void update(ll l, ll r, ll v){ // Updates from l to r inclusive
	r++;           // Update the difference at r+1 not r
	for(; l <= n; l += ls(l)) ft[l] += v;// Add v to the diff at l
	for(; r <= n; r += ls(r)) ft[r] -= v;// Minus v from diff at r+1
}
ll query(ll p){                     // Returns the element at p
	ll sum = 0;
	for(; p; p -= ls(p)) sum += ft[p];
	return sum; 
}

int main() {
	fastio; cin >> n >> k;
	FOR(i, 1, n) {
		cin >> a;
		sum += a;
		ss[i] = sum - i*k;
		v.pb(ss[i]);
	}
	sort(v.begin(), v.end());
	FOR(i, 1, n) {
		if (ss[i] >= 0) ans++;
		ss[i] = lower_bound(v.begin(), v.end(), ss[i]) - v.begin() + 1;
		ans += query(ss[i]);
		update(ss[i], n, 1);
	}
	cout << ans;
}