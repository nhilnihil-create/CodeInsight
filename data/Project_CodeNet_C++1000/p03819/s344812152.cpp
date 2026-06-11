#include <bits/stdc++.h>
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
typedef long long ll;
using namespace std;

int N, M, l, r, res[100002];

int main() {
	cin >> N >> M;
	for (int i = 0; i != N; ++i) {
		cin >> l >> r;
		int p;
		for (p = 1; p <= 400; ++p) {
			if ((l - 1) / p != r / p) {
				++res[p];
				--res[p + 1];
			}
		}
        --p;
		for (int j = 300; j; --j) {
			++res[max((l - 1) / j, p) + 1];
			p = max(r / j, p);
			--res[p + 1];
		}
	}
	for (int i = 1; i <= M; ++i) {
		res[i] += res[i - 1];
		cout << res[i] << endl;
	}
	return 0;
}
