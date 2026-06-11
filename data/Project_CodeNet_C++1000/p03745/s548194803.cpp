
// A - Sorted Arrays

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

const int UNCONF = 0;
const int INC = 1;
const int DEC = 2;

int A[100000];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	int cnt = 1;
	int state = UNCONF;
	for (int i=0; i<N-1; i++) {
		if (state == UNCONF) {
			if (A[i] < A[i+1]) state = INC;
			if (A[i] > A[i+1]) state = DEC;
		} else if (state == INC && A[i] > A[i+1]) {
			cnt++;
			state = UNCONF;
		} else if (state == DEC && A[i] < A[i+1]) {
			cnt++;
			state = UNCONF;
		}
	}

	int ans = cnt;

	cout << ans << endl;

	return 0;
}