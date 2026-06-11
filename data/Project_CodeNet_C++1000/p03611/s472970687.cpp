#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<int> v(100000);
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v.at(n)++;
	}

	int ans = 0;
	for (int i = 1; i < v.size() - 1; i++) {
		int sum = v.at(i - 1) + v.at(i) + v.at(i + 1);
		if (sum > ans) ans = sum;
	}

	cout << ans << endl;
}