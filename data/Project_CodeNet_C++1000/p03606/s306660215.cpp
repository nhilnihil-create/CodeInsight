#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	int sum = 0;
	for (int i = 0; i < N; i++) {
		int l, r;
		cin >> l >> r;
		sum += r - l + 1;
	}

	cout << sum << endl;
}