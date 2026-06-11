#include<iostream>
typedef long long ll;
using namespace std;

int main() {
	ll x, t;
	cin >> x >> t;
	if (x < t) cout << 0 << endl;
	else cout << x - t << endl;
 	return 0;
}