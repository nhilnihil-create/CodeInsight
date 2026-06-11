#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int n;
	cin >> n;

	deque<int> deq;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (n % 2 != i % 2) deq.push_front(num);
		else deq.push_back(num);
	}

	for (int i = 0; i < deq.size(); i++) {
		if (i) cout << ' ';
		cout << deq.at(i);
	}
	cout << endl;
}