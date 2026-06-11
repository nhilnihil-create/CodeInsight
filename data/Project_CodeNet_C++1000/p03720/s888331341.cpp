#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> v(N);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		v.at(a - 1)++;
		v.at(b - 1)++;
	}

	for (int i = 0; i < N; i++) {
		cout << v.at(i) << endl;
	}
}