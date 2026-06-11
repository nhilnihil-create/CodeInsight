#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	deque<int>q;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (i & 1)
			q.push_back(x);
		else
			q.push_front(x);
	}
	if (n & 1) {
		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop_front();
		}
	}
	else {
		while (!q.empty()) {
			cout << q.back() << " ";
			q.pop_back();
		}
	}
}