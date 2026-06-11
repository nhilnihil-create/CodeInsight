#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) { 
			int k = i + j;
			if (m - k >= 0 && m - k <= n) {
				cnt++;
			}
		}  
	}
	cout << cnt;
}

















