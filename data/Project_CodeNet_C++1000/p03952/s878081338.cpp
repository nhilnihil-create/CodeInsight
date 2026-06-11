#include <bits/stdc++.h>
using namespace std;

int n, x;
deque<int> ans;

int main() {
	cin >> n >> x;
	if (x == 1 || x == 2 * n - 1)
		return cout << "No\n", 0;
	for (int i = 1; i <= 2 * n - 1; i++)
		ans.push_back(i);
	int res = ans[n - 1];
	while (res != x) {
		int tmp = ans.back();
		ans.pop_back();
		ans.push_front(tmp);
		res = ans[n - 1];
	}
	cout << "Yes\n";
	for (auto i: ans)
		cout << i << ' ';
	cout << endl;
	return 0;
}
