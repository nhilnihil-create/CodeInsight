#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a[N];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n, greater<int>());
	int lst1 = n, lst2 = n;
	for (int i = 0; i < n; i++) {
		if (a[i] < i + 1) {
			lst1 = i;
			break;
		}
	}
	for (int i = lst1 - 1; i < n; i++) {
		if (a[i] >= lst1)
			lst2 = i;
	}
//	cout << " : " << lst1 << " " << lst2 << " : " << a[lst1] << endl;
	if ((a[lst1 - 1] - lst1) % 2 == 1 || (lst2 - (lst1 - 1)) % 2 == 1)
		cout << "First";
	else
		cout << "Second";
	return 0;
}
