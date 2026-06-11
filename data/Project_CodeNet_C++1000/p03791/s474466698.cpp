#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

struct Task {
	int n;
	vector<int> a;

	Task(int n): n(n), a(n) {
		for (auto& item : a) {
			cin >> item;
		}
	}

	void run() {
		vector<int> fact(n + 1);
		fact[0] = 1;
		for (int i = 1; i <= n; ++i) {
			fact[i] = (1LL * fact[i - 1] * i) % mod;
		}
		int result = 1;
		int cur = 1;
		for (int i = 0; i < n; ++i) {
			if (a[i] < cur) {
				int pref = (cur+1)/2;
				result = (1LL * result * pref) % mod;
			} else
			cur += 2;
		}
		result = (1LL * result * fact[(cur-1)/2]) % mod;
		cout << result << endl;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	Task a(n);
	a.run();

	return 0;
}