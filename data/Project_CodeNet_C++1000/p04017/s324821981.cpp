/// In The Name Of God

#include <bits/stdc++.h>

#define f first
#define s second

#define pb push_back
#define pp pop_back
#define mp make_pair

#define sz(x) (int)x.size()
#define sqr(x) ((x) * 1ll * (x))
#define all(x) x.begin(), x.end()

#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, l, r) for (int i = (l); i >= (r); i--)

#define Kazakhstan ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define nl '\n'
#define ioi exit(0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = (int)1e5 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;

const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

using namespace std;

int n, L;
int a[N], Right[20][N], Left[20][N];
int main() {
	#ifdef IOI2018
		freopen ("in.txt", "r", stdin);
	#endif
	Kazakhstan
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	cin >> L;

	/// calculating Rights
	int ptr = n;
	per(i, n, 1) {
		while (a[ptr] - a[i] > L) ptr--;
		Right[0][i] = ptr;
	}
	/// Calculating Lefts
	ptr = 1;
	rep(i, 1, n) {
		while (a[i] - a[ptr] > L) ptr++;
		Left[0][i] = ptr;
	}
	rep(dg, 1, 19) {
		rep(i, 1, n) {
			Right[dg][i] = Right[dg - 1][Right[dg - 1][i]];
			Left[dg][i] = Left[dg - 1][Left[dg - 1][i]];
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		int ans = 0;
		if (l > r) swap(l, r);
		if (l < r) {
			per(i, 19, 0) {
				if (Right[i][l] < r) {
					l = Right[i][l];
					ans += (1 << i);
				}
			}
			++ans;
		}
		else {
			per(i, 19, 0) {
				if (Left[i][l] > r) {
					l = Left[i][l];
					ans += (1 << i);
				}
			}
			++ans;
		}
		cout << ans << nl;
	}
	ioi
}
