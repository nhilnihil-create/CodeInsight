#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> a(N), b(N), c(M), d(M);
	for (int i = 0; i < N; i++) {
		cin >> a.at(i) >> b.at(i);
	}
	for (int i = 0; i < M; i++) {
		cin >> c.at(i) >> d.at(i);
	}

	for (int i = 0; i < N; i++) {
		int dif, sub;

		for (int j = 0; j < M; j++) {
			int n = abs(a.at(i) - c.at(j)) + abs(b.at(i) - d.at(j));

			if (!j) {
				dif = n;
				sub = j + 1;
			}
			else {
				if (dif > n) {
					dif = n;
					sub = j + 1;
				}
			}
		}

		cout << sub << endl;
	}
}