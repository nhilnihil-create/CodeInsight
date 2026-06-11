#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int N, M, A[309][309], cnt;
bool used[309];

bool solve(int border) {
	for (int i = 1; i <= M; i++) used[i] = false;
	cnt = M;
	while (true) {
		int cntv[309];
		for (int i = 1; i <= M; i++) cntv[i] = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (used[A[i][j]] == false) { cntv[A[i][j]]++; break; }
			}
		}
		int r = 0;
		for (int i = 1; i <= M; i++) {
			if (cntv[i] > border) { used[i] = true; cnt--; r = 1; }
		}
		if (r == 0) break;
		if (cnt == 0) return false;
	}
	return true;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cin >> A[i][j];
	}

	int cl = 1, cr = N + 1, cm, minx = (1 << 30);
	for (int i = 0; i < 12; i++) {
		cm = (cl + cr) / 2;
		bool I = solve(cm);
		if (I == true) { minx = min(minx, cm); cr = cm; }
		else { cl = cm; }
	}
	cout << minx << endl;
	return 0;
}