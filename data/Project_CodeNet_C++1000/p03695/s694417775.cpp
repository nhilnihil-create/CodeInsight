#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N;
	cin >> N;
	int ans[9] = { 0 };

	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;

		if (1 <= a && a <= 399) {
			ans[0]++;
		}
		else if (400 <= a && a <= 799) {
			ans[1]++;
		}
		else if (800 <= a && a <= 1199) {
			ans[2]++;
		}
		else if (1200 <= a && a <= 1599) {
			ans[3]++;
		}
		else if (1600 <= a && a <= 1999) {
			ans[4]++;
		}
		else if (2000 <= a && a <= 2399) {
			ans[5]++;
		}
		else if (2400 <= a && a <= 2799) {
			ans[6]++;
		}
		else if (2800 <= a && a <= 3199) {
			ans[7]++;
		}
		else if (3200 <= a){
			ans[8]++;
		}
	}

	int cnt = 0;
	for (int i = 0; i < 8; ++i) {
		if (ans[i] > 0) {
			cnt++;
		}
	}

	int maxval = cnt + ans[8];
	int minval = cnt;
	if (cnt == 0) {
		minval = 1;
	}

	cout << minval << " " << maxval << endl;
	return 0;
}
