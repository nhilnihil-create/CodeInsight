#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	deque<int>q;
	bool r = true;
	if (n % 2 == 1)r = false;
	for (int i = 0; i < n; i++) {
		if (r) {
			q.push_back(a.at(i));
			r = false;
		}
		else {
			q.push_front(a.at(i));
			r = true;
		}
	}
	cout << q.front();
	q.pop_front();
	while (q.size() > 0) {
		cout << " " << q.front();
		q.pop_front();
	}
	cout << endl;
}