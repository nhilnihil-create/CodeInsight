#include <bits/stdc++.h>
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int N, T, A, mn, mx, cnt;

int main() {
	cin >> N >> T;
	mn = intmax;
	for (int i = 0; i != N; ++i) {
		cin >> A;
		mn = min(mn, A);
		if (mx == A - mn) {
			++cnt;
		}
		if (mx < A - mn) {
			cnt = 1;
			mx = A - mn;
		}
	}
	cout << cnt << endl;
	return 0;
}