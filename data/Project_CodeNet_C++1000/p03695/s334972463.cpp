#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;
template<typename T> void print(T t) {cout << t << endl;}
;
int main() {
	int N, a, over3200 = 0;
	cin >> N;
	bool col[8] = {};
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a / 400 <= 7) {
			col[a / 400] = true;
		}
		else {
			over3200++;
		}
	}

	int under3200 = 0;
	for (int i = 0; i < 8; i++) {
		if (col[i]) under3200++;
	}

	cout << max(under3200, 1) << " " << under3200 + over3200 << endl;
}