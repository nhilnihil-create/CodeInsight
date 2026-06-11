#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>a(n + 5);
	for (int i = 0, tmp; i < n; i++) {
		cin >> tmp; a[i] = tmp;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == i + 1)ans++, swap(a[i], a[i + 1]);
	}
	cout << ans << endl;

	return 0;
}