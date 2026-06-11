#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
int cnt[101];
int main() {
	int N;
	cin >> N;
	int M = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		cnt[a]++;
		M = max(M, a);
	}
	if (N == 2) {
		if (cnt[1] != 2) cout << "Impossible" << endl;
		else cout << "Possible" << endl;
		return 0;
	}
	if (cnt[1] > 0) {
		if (cnt[2] != N - 1) cout << "Impossible" << endl;
		else cout << "Possible" << endl;
		return 0;
	}
	bool ok = 1;
	if (M % 2) {
		int m = (M + 1) / 2;
		for (int i = M; i > m; i--) {
			if (cnt[i] < 2) ok = 0;
		}
		for (int i = 1; i < m; i++) {
			if (cnt[i] > 0) ok = 0;
		}
		if (cnt[m] != 2) ok = 0;
	}
	else {
		int m = M / 2;
		for (int i = M; i > m; i--) {
			if (cnt[i] < 2) ok = 0;
		}
		for (int i = 1; i < m; i++) {
			if (cnt[i] > 0) ok = 0;
		}
		if (cnt[m] != 1) ok = 0;
	}
	if (ok) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}
