#include <bits/stdc++.h>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);++i)

using namespace std;

int main () {
	int a, b, c; cin >> a >> b >> c;

	if (a % (b + c) == 0) cout << "Yes" << '\n';
	else if (b % (a + c) == 0) cout << "Yes" << '\n';
	else if (c % (a + b) == 0) cout << "Yes" << '\n';
	else cout << "No" << '\n';

	return 0;

}