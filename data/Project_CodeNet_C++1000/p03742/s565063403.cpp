#include<bits/stdc++.h>
using ll = long long;
using namespace std;
signed main() {
	ll n, x; cin >> n >> x;
	if (abs(n - x) <= 1) { cout << "Brown\n"; }
	else { cout << "Alice\n"; }
    return 0;
}