#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), greater<int>());
	int pos = 0;
	while (pos != n && a[pos] > pos) ++pos;
	--pos;
	int cnt = 0;
	for (int i = pos + 1; i < n; ++i) {
		if (a[i] > pos) ++cnt;
	}
	bool f1 = ((a[pos] - pos - 1) % 2 == 1);
	bool f2 = (cnt % 2 == 1);
	cout << (f1 || f2 ? "First\n" : "Second\n");
	return 0;
}