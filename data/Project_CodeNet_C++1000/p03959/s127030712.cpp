#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

#define int long long
#define rep(i, n) for (int i=0;i<(int)(n);++i)
#define rep1(i, n) for (int i=1;i<=(int)(n);++i)
#define rrep1(i, n) for (int i=n;i>=1;--i)
#define all(a) begin(a),end(a)

using vi = vector<int>;
using pii = pair<int, int>;

const int inf = 1e9 + 5;

int N;
int T[100010], A[100010];
bool decided[100010];

signed main()
{
	cin >> N;
	rep1(i, N) cin >> T[i];
	rep1(i, N) cin >> A[i];

	rep1(i, N) {
		if (T[i] > T[i - 1]) {
			decided[i] = true;

			if (T[i] > A[i]) {
				cout << 0 << endl;
				return 0;
			}
		} 
	}

	rrep1(i, N) {
		if (A[i] > A[i + 1]) {
			decided[i] = true;

			if (A[i] > T[i]) {
				cout << 0 << endl;
				return 0;
			}
		}
	}

	int ans = 1;

	rep1(i, N) {
		if (decided[i]) continue;

		ans *= min(A[i], T[i]);
		ans %= 1000000007;
	}

	cout << ans << endl;
}

