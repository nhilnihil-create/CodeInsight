#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;

const int mod = 1e9 + 7;

vector<long long> fact;

void make_fact(int n) {
	fact.assign(n + 1, 1);
	for (int i = 2; i <= n; i++) {
		fact[i] = fact[i - 1] * i % mod;
	}
}

int main() {
	int n;
	cin >> n;

	make_fact(n);

	vector<int> x(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	long long ret = 1;
	stack<long long> st;
	for (auto y : x) {
		if (st.empty()) {
			st.push(1);
			continue;
		}

		auto a = st.top();
		if (y >= a + 2) {
			st.push(a + 2);
		} else {
			ret = ret * (st.size() + 1) % mod;
		}
	}

	if (!st.empty()) {
		ret = ret * fact[st.size()] % mod;
	}

	cout << ret << endl;
	return 0;
}
