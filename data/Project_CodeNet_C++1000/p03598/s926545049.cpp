#include<bits/stdc++.h>
using namespace std;

int main () {
	int n, k;
	int x;
	cin >> n;
	cin >> k;
	int ans=0;
	for (int i=0; i<n; i++) {
		cin >> x;
		ans += min(x-0, k-x)*2;
	}
	cout << ans;
} 