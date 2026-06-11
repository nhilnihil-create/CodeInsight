#include<iostream>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

typedef long long ll;

int N;
ll A[100000 + 10];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> A[i];

	int pos1 = N;
	for (int i = 0; i < N; i++) {
		if (A[i] == 1) {
			pos1 = i;
			break;
		}
	}

	ll ans = A[0] - 1, nowP = 2;
	for (int i = 1; i < N; i++) {
		if (A[i] < nowP);
		else if (A[i] == nowP)nowP++;
		else {
			ans += (A[i] - 1) / nowP;
		}
	}
	cout << ans << endl;
	return 0;
}