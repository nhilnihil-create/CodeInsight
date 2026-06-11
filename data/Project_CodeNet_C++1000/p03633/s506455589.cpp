#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 2つの整数の場合
long long GetLeastCommonMultiple(long long a, long long b)
{
	long long m = a;
	long long n = b;
	long long temp;

	while (m % n != 0) {
		temp = n;
		n = m % n;
		m = temp;
	}
	return a / n * b;
}

int main() {

	ll n; cin >> n;
	vector<ll> t(n);
	for (ll i = 0; i < n; i++) {
		cin >> t[i];
	}
	//sort(t.begin(), t.end());
	long long lcm = t[0];
	for (int i = 1; i < n; i++) {
		lcm = GetLeastCommonMultiple(lcm, t[i]);
	}
	cout << lcm << endl;
	return 0;
}