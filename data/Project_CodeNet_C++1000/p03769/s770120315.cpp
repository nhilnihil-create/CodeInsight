/* In the name of Allah */
#include<bits/stdc++.h>
using namespace std;

int main() {
	long n;
	cin >> n;
	deque<int> dq;
	int mn = 1, mx = 100;
	for (n++; n > 1; n >>= 1) {
		if (n & 1)
			dq.push_back(mx--);
		dq.push_back(mn++);
	}
	for (int i = 100; i; i--)
		if (i > mx || i < mn)
			dq.push_front(i);
	cout << dq.size() << endl;
	for (auto x: dq)
		cout << x << ' ';
}
