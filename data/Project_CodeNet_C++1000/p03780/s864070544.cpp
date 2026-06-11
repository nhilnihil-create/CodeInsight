#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>

using namespace std;
typedef long long ll;

int main() {
	int N, K; cin >> N >> K;
	int* a = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	bitset<5000>* table = new bitset<5000>[N];
	for (int i = 0; i < N; i++) {
		table[i] = 0;
	}
	table[N - 1][0] = true;
	for (int i = N - 1; i >= 0; i--) {
		if (i < N - 1) { table[i] = table[i + 1]; }
		table[i] |= table[i] << a[i];
	}

	int ans = 0;
	bitset<5000> bset;
	bset[0] = true;
	for (int i = 0; i < N; i++) {
		bool found = false;
		if (i == 0) {
			for (int j = max(0, K - a[i]); j < K; j++) {
				if (table[i + 1][j] == true) { found = true; break; }
			}
		}
		else if (i == N - 1) {
			for (int j = max(0, K - a[i]); j < K; j++) {
				if (bset[j] == true) { found = true; break; }
			}
		}
		else {
			int x = max(0, K - a[i]);
			int y = K;
			int count = 0;
			for (int j = x; j < y; j++) {
				if (table[i + 1][j] == true) { count++; }
			}
			for (int j = 0; j < K; j++) {
				if (bset[j] == true && count > 0) { found = true; break; }
				x--; y--;
				if (x >= 0) { count += (table[i + 1][x] == true); }
				count -= (table[i + 1][y] == true);
			}
		}
		if (found == false) { ans++; }

		bset |= bset << a[i];
	}

	cout << ans << endl;

	return 0;
}