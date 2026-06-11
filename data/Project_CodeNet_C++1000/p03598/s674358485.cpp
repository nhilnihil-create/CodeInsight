#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N, K;
	cin >> N >> K;

	int sum = 0;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		int n = min(x, abs(K - x));
		sum += n;
	}

	cout << sum * 2 << endl;
}
