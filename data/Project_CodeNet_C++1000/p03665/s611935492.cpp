#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long  ll;

int main() {
	ll N, P;
	cin >> N >> P;
	bool flag = true;
	ll ans = 1;
	for (ll i = 0; i < N; i++)
	{
		ll temp = 0;
		cin >> temp;
		if (temp % 2) flag = false;
		ans *= 2;
	}
	ans /= 2;
	if (flag) {
		if (P == 1) {
			cout << 0 << endl;
		}
		else {
			cout << ans * 2 << endl;
		}
	}
	else {
		cout << ans << endl;
	}
	return 0;
}