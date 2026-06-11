#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c; cin >> a >> b >> c;
	if((a+b+c)%17 == 0) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	
	return 0;
}
