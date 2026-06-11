#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int64_t N, T;
	cin >> N >> T;

	vector<int64_t> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v.at(i);
	}

	int64_t sum = T;
	for (int i = 1; i < N; i++) {
		sum += min(v.at(i) - v.at(i - 1), T);
	}

	cout << sum << endl;
}