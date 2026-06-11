#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int x, y; cin >> x >> y;
	vector<int> c = { 0,1,3,1,2,1,2,1,1,2,1,2,1 };
	string ans;
	if (c[x] == c[y]) ans = "Yes";
	else ans = "No";
	cout << ans << endl;
	return 0;
}