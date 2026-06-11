
// C - pushpush

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int n;
	cin >> n;

	vector<int> head, tail;

	int a;
	for (int i=0; i<n; i++) {
		cin >> a;

		if (i % 2 == 0) tail.push_back(a);
		else head.push_back(a);
	}

	if (n % 2 == 0) {
		reverse(head.begin(), head.end());
		bool first = true;
		for (int b : head) {
			if (first) first = false;
			else cout << " ";

			cout << b;
		}
		for (int b : tail) {
			cout << " ";
			cout << b;
		}
		cout << endl;
	} else {
		reverse(tail.begin(), tail.end());
		bool first = true;
		for (int b : tail) {
			if (first) first = false;
			else cout << " ";

			cout << b;
		}
		for (int b : head) {
			cout << " ";
			cout << b;
		}
		cout << endl;
	}

	return 0;
}