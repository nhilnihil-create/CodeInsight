#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 18], D[1 << 18];
long long S;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) S += A[i];
	
	long long base = N * (N + 1LL) / 2LL;
	long long kosuu = S / base;
	if (S % base != 0) {
		cout << "NO" << endl;
		return 0;
	}

	long long t = 0, cnt = 0;
	for (int i = 1; i <= N; i++) D[i] = A[i] - 1LL * i * kosuu;
	for (int i = 2; i <= N; i++) {
		if (D[i] == D[i - 1]) continue;
		if (D[i - 1] < D[i]) { cout << "NO" << endl; return 0; }
		if ((D[i] - D[i - 1]) % N != 0) { cout << "NO" << endl; return 0; }
		long long s = (D[i - 1] - D[i]) / N;
		cnt += s;
		t += 1LL * (N + 2 - i) * s;
	}

	if (kosuu < cnt) { cout << "NO" << endl; return 0; }
	t += 1LL * (kosuu - cnt);
	if (t == A[1]) { cout << "YES" << endl; }
	else { cout << "NO" << endl; }
	return 0;
}