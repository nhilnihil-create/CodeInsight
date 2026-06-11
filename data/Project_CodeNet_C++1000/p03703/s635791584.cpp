//IOI 2021
//labriz kon code ra, ham paye ie AC manam, AC age yari kone ta sob man code miznm :)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2 * 100 * 1000 + 17;

ll n, k, a[MAXN];

ll DC(int l, int r) {
	if (l + 1 == r)
		return (a[l] >= k);
	int mid = (l + r) / 2;
	ll res = DC(l, mid) + DC(mid, r);
	vector<ll> part1, part2;
	ll sum = 0;
	for (int i = mid - 1; i >= l; i--)
		sum += a[i], part1.pb(sum);
	sum = 0;
	for (int i = mid; i < r; i++)
		sum += a[i], part2.pb(k * (i - mid + 1) - sum);
	sort(part2.begin(), part2.end());
	for (int i = 0; i < part1.size(); i++) {
		int ind = upper_bound(part2.begin(), part2.end(), part1[i] - k * (i + 1)) - part2.begin();
		res += ind;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << DC(1, n + 1) << endl;
	return 0;
}
