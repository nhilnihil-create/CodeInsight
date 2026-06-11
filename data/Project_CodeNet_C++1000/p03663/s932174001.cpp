#include <bits/stdc++.h>
#define int 	long long
using namespace std;

int n;
int dig[11];
string res;

bool chec(long long x) {
	char f;
	cout << "? " << x << "\n";
	cout.flush();
	cin >> f;
	if (f == 'Y') return true;
	if (f == 'N') return false;
}

long long p(int n, int k) {
	if (k == 0) return 1ll;
	if (k == 1) return n;
	long long cur = p(n, k/2);
	if (k % 2 == 0) {
		return cur * cur;
	}
	else {
		return cur * cur * n;
	}
}

signed main() {
	if (chec(1000000000)) {
		int res = -1;
		for (int j = 3; j >= 0; j--) {
			if ((1ll<<j) > 10 || res + (1ll<<j) > 10) continue;
			if (!chec(2ll*p(10, (1<<j)+res))) {
				res += (1ll<<j);
			}
		}
		res++;
		cout << "! 1";
		for (int i = 1; i <= res; i++) {
			cout << 0;
		}
	}
	else {
		int res = 0;
		int l = 0;
		for (int j = 3; j >= 0; j--) {
			if ((1<<j) > 10 || l + (1<<j) > 10) continue;
			if (chec(p(10, (1<<j)+l))) {
				l += (1<<j);
			}
		}
		l++;
		//cout << l << endl;
		int ul = p(10, l)-1;
		res = p(10, l-1);
		for (int j = 30; j >= 0; j--) {
			if ((1ll<<j) > ul || res + (1ll<<j) > ul) continue;
			if (!chec(10 * (res + (1ll<<j)))) {
				res += (1ll << j);
			}
		}
		cout << "! " << res+1;
	}
	return 0;
}