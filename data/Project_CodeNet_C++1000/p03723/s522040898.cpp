#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;
int main() {
	int a, b, c, na, nb, nc;
	int ans = 0;
	cin >> a >> b >> c;
	for (int i = 0; i < 1000; i++) {
		if (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
			na = (b + c) / 2;
			nb = (a + c) / 2;
			nc = (b + a) / 2;
			ans++;
			if (na == a && nb == b && nc == c) {
				ans = -1;
				break;
			}
			a = na;
			b = nb;
			c = nc;
		}
		else {
			break;
		}
	}
		cout << ans << endl;
		return 0;
}
