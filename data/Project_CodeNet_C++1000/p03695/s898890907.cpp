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

int N, A[12];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int C; cin >> C;
		A[min(8, C / 400)] += 1;
	}
	int cnt = 0;
	for (int i = 0; i <= 7; i++) {
		if (A[i] >= 1) cnt++;
	}
	if (cnt == 0) cout << 1 << " " << A[8] << endl;
	else cout << cnt << " " << cnt + A[8] << endl;
	return 0;
}