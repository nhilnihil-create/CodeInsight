#include <bits/stdc++.h>
using namespace std;

#define li long long int
#define rep(i, to) for (li i = 0; i < ((li)(to)); i++)
#define repp(i, start, to) for (li i = (li)(start); i < ((li)(to)); i++)
#define allof(v) (v).begin(), (v).end()

li n, k;
li a[100100];

li all_sum[100100];
li plus_sum[100100];

int main(void)
{
	cin >> n >> k;
	rep(i, n) {
		cin >> a[i];
	}
	all_sum[0] = 0;
	plus_sum[0] = 0;
	rep(i, n) {
		all_sum[i + 1] = all_sum[i] + a[i];
		plus_sum[i + 1] = plus_sum[i];
		if (a[i] > 0) {
			plus_sum[i + 1] += a[i];
		}
	}

	li res = 0;
	rep(i, n - k + 1) {
		res = max(res, max(0ll, all_sum[i + k] - all_sum[i])
		          + plus_sum[n] - plus_sum[i + k] + plus_sum[i]);
	}
	cout << res << endl;


	return 0;
}