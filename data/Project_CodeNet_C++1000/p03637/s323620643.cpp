#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	int num_four = 0;
	int num_two = 0;
	for (ll i = 0; i < n; i++) {
		ll a; cin >> a;
		if (a % 4 == 0) num_four++;
		else if (a % 2 == 0) num_two++;
	}
	int num_result = n - num_four - num_two;
	bool can = false;
	if (n % 2 != 0) {
		if (num_result - num_four <= 1) {
			can = true;
		}
		else {
			can = false;
		}
	}
	else { // n % 2 == 0
		if (num_result - num_four <= 0) {
			can = true;
		}
		else {
			can = false;
		}
	}
	if (can) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}