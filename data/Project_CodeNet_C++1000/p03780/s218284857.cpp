#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool uin(T& a, T b) { return a > b ? (a = b, true) : false; }
template <class T>
inline bool uax(T& a, T b) { return a < b ? (a = b, true) : false; }

using namespace std;
const int nax = 5010;

int N, K;
int len, A[nax];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	len = 0;
	int ans = N;
	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		if (x >= K) {
			ans--;
		} else {
			A[len++] = x;
		}
	}
	sort(A, A + len);
	int tmp = 0;
	while (len >= 2) {
		tmp += A[len - 1];
		if (A[len - 2] + tmp < K) {
			len--;
			continue;
		}
		if (A[0] + tmp >= K) {
			ans = 0;
			break;
		}
		int l = 0, r = len - 2;
		while (l + 1 < r) {
			int mid = (l + r) / 2;
			if (tmp + A[mid] >= K) {
				r = mid;
			} else {
				l = mid;
			}
		}

		ans = ans - (len - r);
		len = r;
	}
	cout << ans << endl;
	return 0;
}