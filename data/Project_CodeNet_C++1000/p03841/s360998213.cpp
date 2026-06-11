#include <bits/stdc++.h>

using namespace std;

int ans[250001];

// numをcount回rightまでに書き込む
struct Task {
	int num, count;
	int right;
	Task(int n, int c, int r) : num(n), count(c), right(r) {}
	bool operator< (const Task& a) const {
		return a.right < (*this).right;
	}
};

signed main() {
	int n; cin >> n;
	vector<vector<Task>> tasks(n * n + 1); // tasks[i]:i始点のtask
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		ans[x] = i;
		if (i - 1 > 0 && x > 1)
			tasks[1].push_back(Task(i, i - 1, x - 1));
		else if (i - 1 > 0 && x == 1) {
			cout << "No" << endl;
			return 0;
		}
		if (n - i > 0 && x + 1 <= n * n)
			tasks[x + 1].push_back(Task(i, n - i, n * n));
		else if (n - i > 0 && x + 1 > n * n) {
			cout << "No" << endl;
			return 0;
		}
	}
	priority_queue<Task> q;
	for (int i = 1; i <= n * n; ++i) {
		for (auto t : tasks[i]) q.push(t);
		if (ans[i]) continue;
		if (q.size() == 0) {
			cout << "No" << endl;
			return 0;
		}
		Task T = q.top(); q.pop();
		if (T.right < i) {
			cout << "No" << endl;
			return 0;
		}
		ans[i] = T.num; T.count--;
		if (T.count > 0)
			q.push(T);
	}
	cout << "Yes" << endl;
	for (int i = 1; i <= n * n; ++i)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}