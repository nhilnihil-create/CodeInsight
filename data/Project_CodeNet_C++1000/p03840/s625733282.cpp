#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	ll ai, ao, at, aj, al;
	cin >> ai >> ao >> at >> aj >> al;
	ll res = ao;
	if (ai & aj & al & 1)
		res += ai + aj + al;
	else if (ai == 0 || al == 0 || aj == 0) {
		res += (ai / 2 * 2) + (al / 2 * 2) + (aj / 2 * 2);
	}
	else {
		ll tmp1 = (ai / 2 * 2) + (al / 2 * 2) + (aj / 2 * 2);
		ll tmp2 = 3 + ((ai - 1) / 2 * 2) + ((al - 1) / 2 * 2) + ((aj - 1) / 2 * 2);
		res += max(tmp1, tmp2);
	}
	cout << res << endl;
	return 0;
}