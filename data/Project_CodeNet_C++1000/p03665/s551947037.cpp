#include <bits/stdc++.h>
using namespace std;
uint64_t combi(uint64_t n, uint64_t x) {
	uint64_t res = 1;
	if (x == 0) {
		return res;
	}
	for (uint64_t d = 1; d <= x; d++) {
		res *= n--;
		res /= d;
	}
	return res;
}

int main() {
	uint64_t n, p;
	cin >> n >> p;
	vector<uint64_t>a(2, 0);
	for (int i = 0; i < n; i++) {
		uint64_t x = 0;
		cin >> x;
		if (x % 2 == 0)a.at(0)++;
		else a.at(1)++;
	}
	//0がzero個,1がone個あり、その中から個数は自由に選んで、%2=pにする
	//p=1の場合、(oneC1+oneC3+oneC5+...)*(zeroC0+zeroC1+zeroC2+...zeroCzero)
	//p=0の場合、(oneC0+oneC2+oneC4+...)*(zeroC0+zeroC1+zeroC2+...zeroCzero)
	uint64_t ans = 0;
	for (int i = p; i <= n; i = i + 2)ans += combi(a.at(1), i);
	uint64_t zeroans = 0;
	for (int i = 0; i <= a.at(0); i++) {
		zeroans += combi(a.at(0), i);
	}
	ans *= zeroans;
	cout << ans << endl;
}
