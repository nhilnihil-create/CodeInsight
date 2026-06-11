#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;

ll b[51][2];
ll a[51][2];

int main() { 
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i][0] >> a[i][1];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i][0] >> b[i][1];
	}
	for (int i = 0; i < n; ++i) {
		int index = 0;
		ll val = abs(a[i][0] - b[0][0]) + abs(a[i][1] - b[0][1]);
		for (int j = 0; j < m; ++j) {
			ll p = abs(a[i][0] - b[j][0]) + abs(a[i][1] - b[j][1]);
			if (p < val) {
				val = p;
				index = j;
			}
		}
		//cout << val << endl;
		cout << index + 1 << endl;
	}
	return 0; 
} 

