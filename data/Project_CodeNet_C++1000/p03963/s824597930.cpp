#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	long long total = K;
	for (int i = 0; i < N - 1; i++) {
		total *= K - 1;
	}
	cout << total << endl;
}
