#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, max, out;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		long long int x = i * (i + 1) / 2;
		if (x - i < N && N <= x) {
			max = i;
			out = x - N;
			break;
		}
	}
	for (int i = 1; i <= max; i++) {
		if (i != out) {
			cout << i << endl;
		}
	}
}