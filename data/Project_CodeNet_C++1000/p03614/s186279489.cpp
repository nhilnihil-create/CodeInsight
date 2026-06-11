#include <iostream>
using namespace std;

const int MAXN = 1e5 + 10;
int a[MAXN], n, ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		if (a[i] == i + 1)
			ans++, i++;
	}
	cout << ans;
}