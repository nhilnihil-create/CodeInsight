#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	int N; cin >> N;
	vector<ll> A(N);
	rep(i, N)cin >> A[i];

	ll ans = 0;
	int sign = 0;
	for (int i = 1; i < N; i++) {
		int x = A[i] - A[i - 1];
		if (sign == 0) {
			sign = x;
		}
		else if ((sign > 0 && x < 0) || (sign < 0 && x > 0)) {
			ans++;
			sign = 0;
		}
	}

	cout << ans+1 << endl;

	return 0;
}