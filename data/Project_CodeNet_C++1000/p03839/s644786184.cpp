//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100 * 1000 + 17;

ll n, k, a[MAXN], ans, ps[MAXN], ss[MAXN], s[MAXN];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		ps[i] = ps[i - 1] + max(a[i], 0LL), s[i] = s[i - 1] + a[i];
	for (int i = n; i; i--)
		ss[i] = ss[i + 1] + max(a[i], 0LL);
	for (int i = k; i <= n; i++)
		ans = max(ans, ps[i - k] + ss[i + 1] + max(s[i] - s[i - k], 0LL));
	cout << ans << endl;
	return 0;
}
