#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
//-------
char ch;
int qry(ll n) {
	cout << "? " << n << endl;
	fflush(stdout);
	cin >> ch;
	return ch == 'Y';
}
ll kpow(ll a, ll b) {
	ll r = 1;
	while (b > 0) {
		if (b & 1) r = r * a;
		a = a * a, b >>= 1;
	}
	return r;
}
bool check() {
	rep(i, 0, 10) 
		if (!qry(kpow(10, i)))
			return false;
	return true;
}
int len() {
	rep(i, 1, 10)
		if (!qry(kpow(10, i)))
			return i;
	return 10;
}
int main() {
	if (check()) {
		rep(p, 0, 10)
			if (qry(kpow(10, p + 1) - 1)) {
				cout << "! " << kpow(10, p) << endl;
				break;
			}
	} else {
		int L = len();
		ll pre = 0;
		rep(i, 0, L - 1) {
			int l = 0, r = 9;
			while (l + 1 < r) {
				int m = (l + r) >> 1;
				!qry(pre * 10  + m) ? r = m - 1 : l = m; 
			}
			int x;
			if (l == r) {
				x = l;
			} else {
				x = qry(pre * 10 + r) ? r : l;
			}
			pre = pre * 10 + x;
		}
		int l = 0, r = 9;	
		while (l + 1 < r) {
			int m = (l + r) >> 1;
			!qry(pre * 100 + m * 10) ? l = m + 1 : r = m;
		}
		int x;
		if (l == r) {
			x = l;
		} else {
			x = qry(pre * 100 + l * 10) ? l : r;
		}
		pre = pre * 10 + x;
		cout << "! " << pre << endl;
	}
	return 0;
}