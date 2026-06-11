#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int mini = 1000000001;
	int profit = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		mini = min(mini, a[i]);
		int res = a[i] - mini;
		if (res > profit) {
			count = 1;
			profit = res;
		} else if (res == profit) {
			count++;
		}
	}
	cout << count << endl;
	
	return 0;
}
