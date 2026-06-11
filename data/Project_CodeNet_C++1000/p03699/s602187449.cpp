#include<bits/stdc++.h>
using namespace std;
int main () {
	int n;
	cin >> n;
	long long s = 0;
	long long mi = 1e9;
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		if (x%10!=0 && x < mi) mi = x;
		s += x;
	}
	if (mi == 1e9) cout << 0;
	else {
		if (s%10!=0) cout << s;
		else cout << s-mi;
	}
	return 0;
}