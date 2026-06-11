#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll q, h, s, d, n;
	cin >> q >> h >> s >> d;
	cin >> n;
	ll sa = min(q * 4, min(h * 2, s));
	ll da = min(d, sa * 2);
	if (n % 2 == 0) cout << da * (n / 2) << endl;
	else cout << sa + da * (n / 2) << endl;
}