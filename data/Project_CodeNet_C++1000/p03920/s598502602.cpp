#include <iostream>
#include <vector>

#define ll long long 

using namespace std;


int main() {
	ll n;

	cin >> n;

	ll count = 0;

	while(count * (count + 1LL) / 2LL < n) {
		count++;
	}

	ll total = n;

	vector<ll> ans;

	for (ll i = count; i > 0; i--) {
		if (total >= i) {
			total -= i;
			ans.push_back(i);
		}
	}

	for (ll a : ans) {
		cout << a << endl;
	}

	return 0;
}