#include <bits/stdc++.h>
using namespace std;

long long n, x;
long long res;
long long t;
deque <long long> per;

int main() {
	cin >> n >> x;

	for (int i = 1; i <= 2 * n - 1; i++)
		per.push_back(i);

	if (x == 1 || x == 2 * n - 1)
		return cout << "No" << '\n', 0;

	res = per[n - 1];
	
	while (res != x) {
		t = per.back();
		per.push_front(t);
		per.pop_back();
		res = per[n - 1];
	}

	cout << "Yes" << '\n';
	
	for (auto i: per)
		cout << i << " ";
	return 0;
}