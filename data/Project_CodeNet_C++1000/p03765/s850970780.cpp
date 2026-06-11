#include <bits/stdc++.h>
//<(") 
#define ll int 
using namespace std;
 
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
 
const ll mod = 1e9 + 7;
const ll siz = 1e5 + 10;
const ll base = 32;
const ll MAXX = 1e9;

ll n, m;
string a, b;

ll pre[siz][2];

bool check(ll x1, ll y1, ll x2, ll y2) {
	ll val1 = (pre[y1][0] - pre[x1 - 1][0] + mod) % 3;
	ll val2 = (pre[y2][1] - pre[x2 - 1][1] + mod) % 3;
	return (val1 == val2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("INP.txt", "r", stdin);
	//freopen("OUT.txt", "w", stdout);
	cin >> a >> b;
	n = a.size(); m = b.size();
	a = ' ' + a; b = ' ' + b;
	for (ll i = 1; i <= n; i++) {
		pre[i][0] = pre[i - 1][0] + ((a[i] == 'A') ? 1 : -1);
		//cerr << pre[i][0] << ' ';
	}
	//cerr << '\n';
	for (ll i = 1; i <= m; i++) {
		pre[i][1] = pre[i - 1][1] + ((b[i] == 'A') ? 1 : -1);
		//cerr << pre[i][1] << ' ';
	}
	//cerr << '\n';
	ll q;
	cin >> q;
	while (q--) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (check(x1, y1, x2, y2)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}  	 	   		  		 		 	  			  		