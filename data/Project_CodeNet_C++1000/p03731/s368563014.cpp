#include <bits/stdc++.h>
using namespace std;

#define li long long int
#define rep(i, to) for (li i = 0; i < ((li)(to)); i++)
#define repp(i, start, to) for (li i = (li)(start); i < ((li)(to)); i++)
#define allof(v) (v).begin(), (v).end()

li n, t;

int main(void)
{
	cin >> n >> t;
	li res = 0;
	li last = -1;
	rep(i, n) {
		li tt;
		cin >> tt;
		if (tt >= last) {
			res += t;
		} else {
			res += tt + t - last;
		}
		last = tt + t;
	}
	cout << res << endl;

	return 0;
}