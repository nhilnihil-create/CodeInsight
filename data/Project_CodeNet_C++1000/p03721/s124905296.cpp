#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

ll n, k, a, b;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	map<ll, ll>::iterator it;
	
	map<ll, ll> m;
	
	cin >> n >> k;
	ll p = n;
	while (p--) {
		cin >> a >> b;
		m[a] += b;
	}
	for (it = m.begin(); it != m.end(); it++) {
		k -= it -> se;
		if (k <= 0) {
			cout << it -> fi;
			break;
		}
	}
	
}