#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main() {
	int K, T, a, ans = 0, b = -1;
	cin >> K >> T;
	priority_queue<pair<int, int>> c;
	for (int i = 0; i < T; i++) {
		cin >> a;
		c.emplace(a, i);
	}
	while (!c.empty()) {
		pair<int, int> d = c.top();
		c.pop();
		if (b == d.second) {
			if (c.empty()) {
				ans++;
				b = d.second;
				d.first--;
				if (d.first) c.push(d);
			}
			else {
				pair<int, int> e = c.top();
				b = e.second;
				c.pop();
				c.push(d);
				e.first--;
				if (e.first) c.push(e);
			}
		}
		else {
			b = d.second;
			d.first--;
			if (d.first) c.push(d);
		}
	}
	cout << ans;
}