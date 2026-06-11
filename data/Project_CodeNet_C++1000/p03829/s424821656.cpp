#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <bitset>

#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define rep1(i,n) for (int (i) = 1; (i) <= (n); i++)
typedef long long int llint;

using namespace std;

const llint inf = pow(10, 12);

int main(void) {
	int a, b, n;
	cin >> n >> a >> b;

	llint pre, ans = 0;
	cin >> pre;

	rep(i,n-1) {
	  int x;
	  cin >> x;

		if ((x - pre)*a > b) {
		  ans += b;
			pre = x;
		}
		else {
		  ans += (x-pre)*a;
			pre = x;
		}
	}
	cout << ans << endl;
}

