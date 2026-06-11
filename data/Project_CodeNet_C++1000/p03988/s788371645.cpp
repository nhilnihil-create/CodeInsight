#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
	scanf("%d", &N);
	multiset<int> A;
	for (int i = 0; i < N; i++) {
		int d; scanf("%d", &d);
		A.insert(d);
	}

	// on diameter path
	int diam = *A.rbegin();
	int low = diam;
	for (int i = 0; i <= diam; i++) {
		int d = max(i, diam-i);
		if (A.find(d) == A.end()) {
			puts("Impossible");
			return 0;
		}
		A.erase(A.find(d));
		low = min(low, d);
	}

	if (!A.empty() && *A.begin() <= low) {
		puts("Impossible");
	} else {
		puts("Possible");
	}

	return 0;
}
