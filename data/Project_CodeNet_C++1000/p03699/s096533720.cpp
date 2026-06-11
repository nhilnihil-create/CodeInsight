#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <numeric>
#include <vector>
#include <regex>

using namespace std;
using ll = long long;
template<typename T> void print(T t) {cout << t << endl;}


int main() {
	int N, ans = 0, s;
	vector<int> not10;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		ans += s;
		if (s % 10 != 0) not10.push_back(s);
	}

	sort(not10.begin(), not10.end());
	if (ans % 10 == 0) {
		if (not10.empty()) {
			print(0);
		}
		else {
			print(ans - not10[0]);
		}
	}
	else {
		print(ans);
	}
}