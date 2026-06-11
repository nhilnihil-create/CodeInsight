#include <iostream>
#include <algorithm>
using namespace std;

long long N, L[1000009];

int main() {
	cin >> N;
	for (long long i = 0; i < N * 3; i++) cin >> L[i];

	sort(L + 0, L + N * 3);

	long long ret = 0;
	for (int i = 0; i < N; i++) ret += L[N * 3 - 1 - 1 - 2 * i];
	cout << ret;

	return 0;
}