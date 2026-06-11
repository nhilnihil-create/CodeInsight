
// B - Colorful Creatures

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll A[100000];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	sort(A, A+N);

	int invalid_colors = 0;
	ll size = 0;

	for (int i=0; i<N-1; i++) {
		size += A[i];
		if (size * 2 < A[i+1]) invalid_colors = i + 1;
	}

	int ans = N - invalid_colors;

	cout << ans << endl;

	return 0;
}