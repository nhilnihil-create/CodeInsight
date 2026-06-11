#include <bits/stdc++.h>
using namespace std;

int main() {
	// cin.tie(0);
	// ios::sync_with_stdio(false);

	int N;
	scanf("%d", &N);

	int A;
	bool rest = false;
	long long result = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &A);
		result += A / 2;
		if (A % 2 == 1) {
			if (rest) {
				result++;
				rest = false;
			} else {
				rest = true;
			}
		} else if (A == 0) {
			rest = false;
		}
	}

	cout << result;
	return 0;
}