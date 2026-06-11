#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string a, b, c; cin >> a >> b >> c;
	if (a.back() == b[0] && b.back() == c[0]) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}