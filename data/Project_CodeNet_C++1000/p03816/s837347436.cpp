#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	if ((n - a.size()) % 2)
		cout << a.size() - 1 << endl;
	else
		cout << a.size() << endl;
	return 0;
}