#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

signed main() {
	int a, b;
	cin >> a >> b;
	if(b < 0) {
		if ((b - a+1) & 1) cout << "Negative" << endl;
		else cout << "Positive" << endl;
	}
	else if(a > 0) cout << "Positive" << endl;
	
	else cout << "Zero" << endl;
}
