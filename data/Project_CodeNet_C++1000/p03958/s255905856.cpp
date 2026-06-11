#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int K, T;
	cin >> K >> T;
	int m = 0;
	rep(i, T) {
		int a;
		cin >> a;
		if (m < a) m = a;
	}
	cout << max(2 * m - K - 1, 0) << endl;
	return 0;
}