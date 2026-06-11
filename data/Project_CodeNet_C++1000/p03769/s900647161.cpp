#include <iostream>
#include <deque>

using namespace std;

deque<int> seq(long long n) {
	if (n == 1) return {};
	if (n % 2 == 0) {
		auto s = seq(n / 2);
		s.push_back(s.size() + 1);
		return s;
	} else {
		auto s = seq(n - 1);
		s.push_front(s.size() + 1);
		return s;
	}
}

int main() {
	long long n;

	cin >> n;

	auto s = seq(n + 1);
	cout << s.size() * 2 << endl;
	for (int x: s) cout << s.size() + 1 - x << ' ';
	for (int i = s.size(); i >= 1; --i) cout << i << ' ';
	cout << endl;

	return 0;
}