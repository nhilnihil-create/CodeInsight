#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll n, a, b, cur, prev, fat = 0; cin >> n >> a >> b;
	cin >> prev;
	for (int i = 0; i < n-1; i++) {
		cin >> cur;
		fat += min(b, (cur-prev)*a);
		prev = cur;
	}
	cout << fat;
	return 0;
}