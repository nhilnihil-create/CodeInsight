#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, T, a;
	cin >> N >> T;
	int total = 0;
	for (int i = 0; i < T; i++) {
		cin >> a;
		if (N < 2 * a) {
			total += 2 * a - N - 1;
		}
	}
	cout << total << endl;
}