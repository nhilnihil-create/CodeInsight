#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v.at(i);
	}

	int wt = 0;
	int i = 0;
	while (wt <= N) {
		wt++;
		int n = v.at(i) - 1;
		if (n == 1) break;
		else i = n;
	}

	if (wt <= N) cout << wt << endl;
	else cout << -1 << endl;
}