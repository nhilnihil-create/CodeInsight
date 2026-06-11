#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v.at(i);
	}
	sort(v.begin(), v.end());

	int sum = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		int n = N - K - 1;
		if (n == i) break;
		sum += v.at(i);
	}

	cout << sum << endl;
}