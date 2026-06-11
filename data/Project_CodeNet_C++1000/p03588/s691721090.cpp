#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void) {
	int n, a, b;
	cin >> n;
	vector<pair<int, int> > num(n);
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		num[i] = { a,b };
	}
	sort(num.begin(), num.end());
	cout << num[n - 1].first + num[n - 1].second << endl;
	return 0;
}