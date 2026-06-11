#include <bits/stdc++.h>
using namespace std;
int main() {
	int64_t n;
	cin >> n;
	int odd = 0;
	int even = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x % 2 == 0)even++;
		else odd++;
	}
	if (odd == 0||odd%2==0||odd+even==1) {
		cout << "YES" << endl;
	}
	else  {
		cout << "NO" << endl;
	}
}