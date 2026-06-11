#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
int mod = 1e9 + 7;

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	ll sum = 0;
	for (ll i = 0; i <= 100; ++i) {
		sum = a  * (i + 1);
		//cout << sum << endl;
		if (sum % b == c) {
			cout << "YES";
			return 0;
				
			}
	}
	cout << "NO";
}

















