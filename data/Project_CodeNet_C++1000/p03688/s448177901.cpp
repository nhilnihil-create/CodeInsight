/*input
5
1 1 1 2 2
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	if(a[n-1] - a[0] > 1) {
		cout << "No\n";
	}
	else if(a[n-1] - a[0] == 0) {
		if(a[0] == n-1) {
			cout << "Yes\n";
		}
		else if(2*a[0] <= n) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
	else {
		int unq = 0;
		for(int i = 0; i < n; i++) {
			if(a[i] == a[0]) unq++;
		}

		int rem = a[n-1] - unq;
		int sz = n - unq;

		if(rem <= 0) {
			cout << "No\n";
		}
		else if(2*rem <= sz) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;  
}