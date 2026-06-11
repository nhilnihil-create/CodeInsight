#include <iostream>
using namespace std;

typedef long long ll;

const int D[10] = { 1, 10, 100, 1000, 10000, 100000, (int)1e6, (int)1e7, (int)1e8, (int)1e9 };

char question(ll n) {
	cout << "? " << n << endl;
	char rsp;
	cin >> rsp;
	return rsp;
}

int solve_pow(void) {
	int n = D[9];
	for (int i = 0; i <= 8; ++i) {
		ll m = 2LL * (ll)D[i];
		char rsp = question(m);
		if (rsp == 'Y') {
			n = D[i];
			break;
		}
	}
	return n;
}

int check_dig(void) {
	int k = 1;
	for (int i = 8; i >= 1; --i) {
		ll m = (ll)D[i];
		char rsp = question(m);
		if (rsp == 'Y') {
			k = i + 1;
			break;
		}
	}
	return k;
}

int solve_dig(void) {
	int k = check_dig();
	int r = D[k] - 1;
	int l = D[k - 1];
	int n;
	while (r - l > 1) {
		n = (l + r) / 2;
		char rsp = question((ll)n * 10);
		if (rsp == 'Y')
			r = n;
		else
			l = n;
	}
	return r;
}

int main(void) {
	int ans;

	char rsp = question((ll)D[9]);
	if (rsp == 'Y')
		ans = solve_pow();
	else
		ans = solve_dig();

	cout << "! " << ans << endl;
	return 0;
}
