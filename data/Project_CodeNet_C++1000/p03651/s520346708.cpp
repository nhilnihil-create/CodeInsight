#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;


int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	ll n, k;	cin >> n >> k;

	vector <ll> v(n);

	for (auto &i: v)	cin >> i;

	ll hcf = v[0];

	rep (i, n) {
		hcf = __gcd(hcf, v[i]);
	}

	if (k % hcf == 0 && k <= *max_element(v.begin(), v.end()))
		cout << "POSSIBLE" << endl;
	else
		cout << "IMPOSSIBLE" << endl;


	return 0;
}