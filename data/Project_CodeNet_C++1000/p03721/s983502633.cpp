#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int64_t N, K;
	cin >> N >> K;

	vector<pair<int64_t, int64_t>> v(N);
	for (int64_t i = 0; i < N; i++) {
		cin >> v.at(i).first >> v.at(i).second;
	}
	sort(v.begin(), v.end());

	int64_t sum = 0;
	for (int64_t i = 0; i < N; i++) {
		sum += v.at(i).second;
		if (K <= sum) {
			cout << v.at(i).first << endl;
			return 0;
		}
	}
}