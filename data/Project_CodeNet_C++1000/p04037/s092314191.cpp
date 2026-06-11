#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int a[N];
int n;
int tp[N];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort (a + 1, a + n + 1, greater<int>());
	for (int i = n; i >= 1; i--) {
		if (a[i] > a[i + 1])
			continue;
		if (tp[i + 1] == 0)
			tp[i] = 1;
	}
	int x = 1;
	while (x < n && a[x + 1] >= x + 1)
		x++;
	if (a[x] == x) {
		if (tp[x]) {
			cout << "First";
			return 0;
		} 
		else {
			cout << "Second";
			return 0;
		}
	}
	if (x + 1 <= n) {
		if (a[x + 1] == x) {
			if (tp[x + 1] == 0) {
				cout << "First";
				return 0;
			}
			if (x % 2 == a[x] % 2) {
				cout << "Second";
				return 0;
			}
			else {
				cout << "First";
				return 0;
			}
		}
	}
	if (x % 2 == a[x] % 2) {
		cout << "Second";
		return 0;
	}
	else {
		cout << "First";
		return 0;
	}
	
	return 0;
}















