#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool is_diff(ll a, ll b) {
	if ((a>0 && b<0) || (a<0 && b>0)) return true;
	else return false;
}

ll f(vector<ll> a, bool flag_first, ll n) {
	ll ans = 0;
	ll total = a[0];

	if (flag_first && a[0]<=0) {ans+=(-a[0])+1;total=1;}
	else if (!flag_first && a[0]>=0) {ans+=(a[0]+1);total=-1;}

	rep(i,n-1) {
		ll next_total = total + a[i+1];
		if (next_total == 0) {
			if (total>0) next_total = -1;
			else next_total = 1;
			ans++;
		}
		else {
			if (is_diff(total, next_total)) total = next_total;
			else {
				if (next_total>0) {total = -1; ans += next_total+1;}
				else {total = 1; ans += (-next_total) + 1;}
			}
		}
	}
	return ans;
}

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	ll ans = min(f(a,true,n), f(a,false,n));
	cout << ans << endl;
	return 0;
}
