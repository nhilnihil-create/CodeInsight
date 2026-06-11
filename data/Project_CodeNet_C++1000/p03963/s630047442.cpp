// ABC046B - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	unsigned int N, K;
	cin >> N >> K;

	unsigned int ans = K;
	for (int i = 1; i < N; i++) {
		ans *= K - 1;
	}

	cout << ans << endl;

	return 0;
}
