#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
 
int main() {
	string a, b;
	cin >> a >> b;
	int A = a.size(), B = b.size();
	if (A > B) {
		cout << "GREATER" << endl;
		return 0;
	}
	if (A < B) {
		cout << "LESS" << endl;
		return 0;
	}
	rep(i, A) {
		int A = int(a[i]), B = int(b[i]);
		if (A > B) {
			cout << "GREATER" << endl;
			return 0;
		}
		if (A < B) {
			cout << "LESS" << endl;
			return 0;
		}
	}
	cout << "EQUAL" << endl;
	return 0;
}