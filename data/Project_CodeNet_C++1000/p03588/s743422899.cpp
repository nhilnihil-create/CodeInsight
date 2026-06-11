#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int N;
	cin >> N;
	int64_t ans = 0;
	int maxA = 0;
	rep(i, N) {
		int A, B;
		cin >> A >> B;
		if (A > maxA) {
			ans = A + B;
			maxA = A;
		}
	}
	cout << ans << endl;
	return 0;
}