#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()

int main() {
	int N, nw = 1;
	cin >> N;
	int A, B;
	ll ans = 0;
	for (int i = 0;i < N;i++) {
		cin >> A;
		if (i == 0) {
			ans += A - 1;
			continue;
		}
		if (A == nw + 1) {
			nw++;
		}
		else if (A > nw) {
			B = A - nw;
			ans += B / (nw + 1);
			B %= (nw + 1);
			if (B > 1)ans++;
		}
	}
	cout << ans << endl;
}