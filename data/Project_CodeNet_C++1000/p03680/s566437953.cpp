#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <map>
using namespace std;

int main() {
	int n, cnt = 0, next = 1;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int j = 0; j < n; j++) {
		cnt++;
		next = a[next - 1];
		if (next == 2) {
			break;
		}
	}
		if (next != 2) {
			cnt = -1;
	}
	cout << cnt << endl;
}