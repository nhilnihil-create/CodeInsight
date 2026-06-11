#include<iostream>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll tate[100000], yoko[100000];

int main() {

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> yoko[i];
	for (int i = 0; i < m; i++)cin >> tate[i];
	ll w = 0, h = 0;
	for (int i = 0; i < n; i++) {
		w += (i * yoko[i] - (n - i - 1) * yoko[i]);
		w %= MOD;
	}
	for (int i = 0; i < m; i++) {
		h += ((i * tate[i]) - (m - i - 1) * tate[i]);
		h %= MOD;
	}

	cout << h * w % MOD << endl;

	return 0;
}