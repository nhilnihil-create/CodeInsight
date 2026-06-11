#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 51;
const ld EPS = 1e-9;

ll items[N];
ll pascal[N][N];

void gen() {
	pascal[0][0] = 1;
	pascal[1][0] = pascal[1][1] = 1;
	for (int i = 2; i < N; i++) {
		pascal[i][0] = pascal[i][i] = 1;
		for (int j = 1; j < i; j++) {
			pascal[i][j] = pascal[i-1][j-1]+pascal[i-1][j];
		}
	}
}

int main () {
	cout.precision(9);
	cout << fixed;
	memset(pascal, 0, sizeof pascal);
	gen();
	int n, A, B; cin >> n >> A >> B; 
	for (int i = 0; i < n; i++)
		cin >> items[i];
	sort(items, items+n);
	reverse(items, items+n);
	ld best = 0;
	for (int i = 0; i < A; i++) 
		best += (ld)items[i];
	best /= (ld)A;

	int num_of_last = 0;
	int req_num = 0;
	for (int i = 0; i < n; i++) {
		if (items[i] == items[A-1]) {
			num_of_last++;
			if (i < A) req_num++;
		}
	}

	ll ans = 0;
	if (req_num == A) {
		// everything is the same number
		for (int i = A; i <= min(B, num_of_last); i++)
			ans += pascal[num_of_last][i];
	} else {
		// only part
		ans += pascal[num_of_last][req_num];
	}

	cout << best << endl << ans << endl;

	return 0;
}
