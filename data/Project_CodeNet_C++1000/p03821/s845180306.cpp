#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	int n; cin >> n;
	vector<ll> a(n), b(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	reverse(a.begin(), a.end()), reverse(b.begin(), b.end());

	ll cur = 0;
	for(int i = 0; i < n; i++) {
		a[i] += cur;
		ll to = (b[i] + a[i] - 1) / b[i];
		cur += (b[i] * to - a[i]);
		//cout << to << " " << to * b[i] << endl;
	}
	cout << cur << endl;

}	