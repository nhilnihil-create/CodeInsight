#pragma GCC optimize "trapv"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	vector< string > a(n);
	for (auto& e:a)
		cin >> e;
	vector< string > b(m);
	for (auto& e:b)
		cin >> e;
	for (int i=0; i<=n-m; i++) {
		for (int j=0; j<=n-m; j++) {
			bool equal = 1;
			for (int k=i; k<i+m && equal; k++) {
				for (int l=j; l<j+m && equal; l++) {
					equal &= a[k][l] == b[k-i][l-j];
				}
			}
			if (equal) return cout << "Yes", 0;
		}
	}
	cout << "No";
	return 0;
}
