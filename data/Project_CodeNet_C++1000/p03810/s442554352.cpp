#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e18;

struct Task {
	int n;
	vector<int> a;

	Task(int n): n(n), a(n) {
		for (auto& item : a) {
			cin >> item;
		}
	}

	void run() {
		int turn = 0;
		while (true) {
			int sum = 0;
			int odd = 0;
			int one = 0;
			for (int i = 0; i < n; ++i) {
				int item = a[i];
				sum ^= (item - 1) & 1;
				if (item & 1) {
					odd = i;
				}
				one |= item == 1;
			}
			if (one) {
				turn ^= sum ^ 1;
				break;
			}
			if (sum) {
				break;
			}
			--a[odd];
			int g = a[odd];
			for (auto& item : a) {
				g = __gcd(item, g);
			}
			for (auto& item : a) {
				item /= g;
			}
			turn ^= 1;
		}
		cout << (!turn ? "First" : "Second") << '\n';
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	Task a(n);
	a.run();

	return 0;
}