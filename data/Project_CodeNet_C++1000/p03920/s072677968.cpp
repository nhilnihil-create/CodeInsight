#include <bits/stdc++.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	int sum = 0, m = 0;
	while (sum < N) {
		++ m;
		sum += m;
	}
	sum = N;
	for (int i = m; sum > 0; -- i) {
		int x = min(i, sum);
		cout << x << endl;
		sum -= x;
	}
}
