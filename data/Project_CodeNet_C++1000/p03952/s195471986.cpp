#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, x; cin >> N >> x;
	if (x == 1 || x == 2 * N - 1)
		cout << "No\n";
	else if (N == 2)
		cout << "Yes\n1\n2\n3\n";
	else if (x < 2 * N - 2) {
		vector<int> res(2 * N - 1, 0);
		res[N - 3] = x + 2;
		res[N - 2] = x - 1;
		res[N - 1] = x;
		res[N] = x + 1;
		int ptr = 0, nx = 1;
		while (ptr < 2 * N - 1) {
			while (res[ptr]) ptr++;
			while (x - 1 <= nx && nx <= x + 2) ++nx;
			res[ptr++] = nx++;
		}
		cout << "Yes\n";
		for (auto resi : res)
			cout << resi << "\n";
	}
	else { // x = 2 * N - 2
		vector<int> res(2 * N - 1,0);
		res[N - 3] = x - 2;
		res[N - 2] = x + 1;
		res[N - 1] = x;
		res[N] = x - 1;
		int ptr = 0, nx = 1;
		while (ptr < 2 * N - 1) {
			while (res[ptr]) ptr++;
			while (x - 2 <= nx && nx <= x + 1) ++nx;
			res[ptr++] = nx++;
		}
		cout << "Yes\n";
		for (auto resi : res)
			cout << resi << "\n";
	}
	return 0;
}