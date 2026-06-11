#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

int main() {
	long N, K;
	cin >> N >> K;
	long *a = new long[N];// 入力
	long w = 0, b = 0;
	long sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		if (a[i] > 0) {
			sum += a[i];
		}
	}
	for (int i = 0; i < K; i++) {
		if (a[i] > 0) {
			w += a[i];
		}
		else if (a[i] < 0) {
			b -= a[i];
		}
	}
	
	long wmin = w, bmin = b;
	for (int i = K; i < N; i++) {
		if (a[i] > 0) {
			w += a[i];
		}
		else if (a[i] < 0) {
			b -= a[i];
		}
		if (a[i - K] > 0) {
			w -= a[i - K];
		}
		else if (a[i - K] < 0) {
			b += a[i - K];
		}

		wmin = min(wmin, w);
		bmin = min(b, bmin);
	}

	cout << sum - min(wmin, bmin) << endl;

	return 0;
}