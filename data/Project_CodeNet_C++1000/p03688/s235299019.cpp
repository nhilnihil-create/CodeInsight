#include <iostream>
#include <map>
using namespace std;

string solve(map<int, int>& count, int n) {
	if (count.size() == 1 && (count.begin()->first == n - 1 || 2 * count.begin()->first <= n)) {
		return "Yes";
	} else if (count.size() == 2 && count.rbegin()->first - count.begin()->first == 1) {
		int x = count.begin()->second, y = count.rbegin()->second;
		if (x + 1 <= count.rbegin()->first && count.rbegin()->first <= x + y / 2) {
			return "Yes";
		}
	}
	return "No";
}

int main() {
	int n;
	cin >> n;
	map<int, int> count;
	for (int a; cin >> a; count[a]++) {
	}
	cout << solve(count, n);
    return 0;
}