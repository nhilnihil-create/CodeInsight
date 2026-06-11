#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	ll n;
	cin >> n;
	ll cnt_odd = 0;
	ll cnt_four = 0;
	rep(i,n) {
		ll a;
		cin >> a;
		if (a%2==1) cnt_odd++;
		else if (a%4==0) cnt_four++;
	}
	if (cnt_odd<=cnt_four) cout << "Yes" << endl;
	else if (cnt_odd==cnt_four+1 && cnt_odd+cnt_four==n) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
