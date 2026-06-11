#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	if (a%2==0 || b%2==0 || c%2==0) {
		cout << 0 << endl;
		return 0;
	}
	ll mi = min(a*b, min(b*c, c*a));
	cout << mi << endl;
	return 0;
}