#include<iostream>

using namespace std;

typedef long long ll;

int main() {
	int N;
	ll A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	for (ll i = 0; i <= N; i++) {
		ll left = C * i - D * (N - 1 - i), right = -C * (N - 1 - i) + D * i;
		if (left <= B - A && B - A <= right) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
