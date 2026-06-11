#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100 * 1000 + 5;

int a[N];
int cnt[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = -a[i];
	}
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--) {
		a[i] = -a[i];
		cnt[i] = cnt[i + 1] + 1;
		if (a[i] != a[i + 1]) {
			cnt[i] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i + 1] < i + 1) {
		//	cout << i << endl;
			if ((a[i] ^ i ^ 1) & 1) {
				cout << "First";
			}
			else {
				cout << "Second";
			}
			return 0;
		}
		if (a[i + 1] == i + 1) {
			if ((a[i] ^ i ^ 1) & 1) {
				cout << "First";
				return 0;
			}
			if ((cnt[i + 1] ^ i ^ a[i + 1] ^ 1) & 1) {
				cout << "Second";
			}
			else {
				cout << "First";
			}
			return 0;
		}
	}
	
/*	if (a[n - 1] & 1) {
		cout << "Second";
	}
	else {
		cout << "First";
	}*/
	return 0; 
}