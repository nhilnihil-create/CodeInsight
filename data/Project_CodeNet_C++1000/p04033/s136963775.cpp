#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
 
int main() {
	int a, b;
	cin >> a >> b;
	if (a * b == 0) cout << "Zero" << endl;
	else if (a > 0 && b > 0) cout << "Positive" << endl;
	else if (a < 0 && b > 0) cout << "Zero" << endl;
	else {
		int now = b - a + 1;
		if (now % 2 == 0) cout << "Positive" << endl;
		else cout << "Negative" << endl; 
	}
	return 0;
}
