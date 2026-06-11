#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
ll a, b;

int main() {
	cin >> a >> b;
	ll ans = a;
	a = a - b;
	if (a < b) swap(a, b);
	while (a % b) {
		ans += (a / b * 2 ) * b;
		a = a % b;
		swap(a, b);
	}
	ans += (a / b * 2 - 1) * b;
	cout << ans << endl;

}