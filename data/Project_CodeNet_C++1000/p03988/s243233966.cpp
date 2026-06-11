#include<bits/stdc++.h>
using namespace std;

int n;
vector <int> a;

int main(void) {
	cin >> n;
	for(int i = 0; i < n; i++) {
		int y;
		cin >> y;
		a.push_back(y);
	}

	sort(a.begin(), a.end());

	int m = a[n - 1];

	if(m == 1) 
		return cout << (n == 2 ? "Possible" : "Impossible") << '\n', 0;
	if(m % 2 == 0) {
		bool ok = true;
		for(long i = m / 2 + 1; i <= m; i++)
			ok &= (upper_bound(a.begin(), a.end(), i) - lower_bound(a.begin(), a.end(), i)) >= 2;
		ok &= a[0] == m / 2;
		ok &= a[1] > m / 2;

		return cout << (ok ? "Possible" : "Impossible") << '\n', 0;
	} 
	else {
		bool ok = true;
		for(long i = (m + 1) / 2; i <= m; i++)
			ok &= (upper_bound(a.begin(), a.end(), i) - lower_bound(a.begin(), a.end(), i)) >= 2;
		ok &= a[0] == (m + 1) / 2;
		ok &= a[1] == (m + 1) / 2;
		ok &= a[2] > (m + 1) / 2;
		return cout << (ok ? "Possible" : "Impossible") << '\n', 0;
	}
}
