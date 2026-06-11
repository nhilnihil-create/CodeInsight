#include<iostream>

using namespace std;

typedef long long ll;

ll K;

int main() {
	cin >> K;
	if (K <= 50) {
		cout << 50 << endl;
		for (int i = 0; i < 50; i++) {
			if (i + K >= 50)cout << i + 1 << " ";
			else cout << 0 << " ";
		}
		cout << endl;
	}
	else {
		cout << 50 << endl;
		ll syou = K / 50LL;
		ll amari = K % 50LL;
		for (ll i = 0; i < 50; i++) {
			ll ret = i + 1;
			if (i + 1 + amari > 50)ret++;
			ret += (syou - 1);
			cout << ret << " ";
		}
		cout << endl;
	}
	return 0;
}