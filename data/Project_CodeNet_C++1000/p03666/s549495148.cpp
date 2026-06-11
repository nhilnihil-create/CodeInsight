#include<iostream>
using namespace std;

typedef long long ll;

ll n, a, b, c, d;

int main() {
	cin >> n >> a >> b >> c >> d;
	for(int i = 0; i < n; i++){
		ll j = n - i - 1;
		if (c * i - d * j <= b - a && b - a <= d * i - c * j) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";

	return 0;
}