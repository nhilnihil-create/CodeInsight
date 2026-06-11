#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL n;
deque<int> ans;

int main() {
	cin >> n;
	++n;
	int cur = 0;
	for (int i = 40; i >= 0; --i) {
		if (n>>i > 1) {
			ans.push_back(++cur);
			if (n>>i&1) {
				ans.push_front(++cur);
			}
		}
	}
	cout << 2*cur << endl;
	for (deque<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
		cout << *it << ' ';
	}
	for (int i = 1; i <= cur; ++i) {
		cout << i << " \n"[i == cur];
	}
	return 0;
}