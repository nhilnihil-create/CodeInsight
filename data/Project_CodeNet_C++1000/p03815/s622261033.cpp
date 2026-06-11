#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll x, cnt; cin >> x;
	cnt = x / 11;
	x = x - cnt * 11;
	cnt = cnt * 2;
	if (x > 6) cnt += 2;
	else if (x > 0) cnt += 1;
	cout << cnt; 
	return 0;
}