#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9 + 7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
	int n;
	cin >> n;
	vector<ll> a(n), t(n);
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> a[i];
	}

	ll T = 1, A = 1;
	for (int i = 0; i < n; i++) {
		//ll co = max(ceil((double)T/t[i]),ceil((double)A/a[i]));　これでWAになる理由が分からない...
		ll x = T / t[i];
		ll y = A / a[i];
		if (T % t[i] != 0) x++;
		if (A % a[i] != 0) y++;
		ll co = max(x, y);
		T = co * t[i];
		A = co * a[i];
	}

	cout << T + A << endl;

	return 0;
}