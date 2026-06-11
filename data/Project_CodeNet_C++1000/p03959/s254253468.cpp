#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
#define ll long long
#define FINISH cout<<0<<endl;return 0
#define MOD 1000000007

int main() {
	ll N;
	cin >> N;
	vector<ll> A(N), B(N), C(N, 0);
	for (int i = 0;i < N;i++)cin >> A[i];
	for (int i = 0;i < N;i++)cin >> B[i];

	C[0] = A[0];
	for (int i = 1;i < N;i++) {
		if (A[i] != A[i - 1])C[i] = A[i];
	}
	if (C[N - 1] > 0 && C[N - 1] != B[N - 1]) {
		FINISH;
	}
	else {
		C[N - 1] = B[N - 1];
	}
	for (int i = N - 2;i >= 0;i--) {
		if (B[i] != B[i + 1]) {
			if (C[i] > 0 && C[i] != B[i]) {
				FINISH;
			}
			else {
				C[i] = B[i];
			}
		}
	}
	
	ll mx = 0;
	for (int i = 0;i < N;i++) {
		mx = max(mx, C[i]);
		if (mx != A[i]) { FINISH; }
	}
	mx = 0;
	for (int i = N - 1;i >= 0;i--) {
		mx = max(mx, C[i]);
		if (mx != B[i]) { FINISH; }
	}

	ll ans = 1;
	for (int i = 0;i < N;i++) {
		if (C[i])continue;
		ans *= min(A[i], B[i]);
		ans %= MOD;
	}
	cout << ans << endl;
}