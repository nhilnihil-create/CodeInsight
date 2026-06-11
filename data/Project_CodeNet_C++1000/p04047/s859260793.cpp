#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	int m = 2 * n;
	vector<int>a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int sum = 0;
	int p;
	for (int i = 0; i < n; i++) {
		p = 2 * i;
		sum += a[p];
	}
	cout << sum << endl;
}