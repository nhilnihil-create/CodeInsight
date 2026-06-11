#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int N;
ll T[100000 + 100], A[100000 + 100];
ll max_ok[100000 + 100], determined[100000 + 100];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> T[i];
	for (int i = 0; i < N; i++)cin >> A[i];

	for (int i = 0; i < N; i++)max_ok[i] = -1;
	ll bef = 0;
	for (int i = 0; i < N; i++) {
		if (bef != T[i]) {
			determined[i] = T[i];
		}
		max_ok[i] = T[i];
		bef = T[i];
	}

	bef = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (!determined[i] && bef != A[i]) {
			determined[i] = A[i];
		}
		else if(determined[i]){
			if (determined[i] > A[i]) {
				cout << 0 << endl;
				return 0;
			}
		}
		if (bef != A[i]) {
			
		}
		max_ok[i] = min(A[i], T[i]);
		bef = A[i];
	}
	ll ans = 1;
	for (int i = 0; i < N; i++) {
		if (determined[i] == 0) {
			ans *= max_ok[i];
			ans %= 1000000007;
		}
	}
	cout << ans << endl;
	return 0;
}