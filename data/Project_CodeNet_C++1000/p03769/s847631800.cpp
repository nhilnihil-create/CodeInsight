#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int main() {
	ll N;
	cin >> N;
	++N;

	vi ans;
	for (int i = 1; i <= 100; ++i) {
		ans.pb(i);
	}

	vi nums, vec;

	int mn = -1, mx = -1;

	while (N) {
		if (N & 1) {
			vec.pb(1);
			--N;
		}

		if (N == 2) {
			mn = mx = 0;
			nums.pb(0);
			break;
		}

		vec.pb(0);
		N /= 2;
	}

	reverse(ALL(vec));

	for (int f : vec) {
		if (mn == -1 && mx == -1) {
			mn = mx = 0;
			nums.pb(0);
			continue;
		}

		if (f == 0) {
			nums.pb(mx + 1);
			++mx;
		} else {
			nums.pb(mn - 1);
			--mn;
		}
	}

	for (int x : nums) {
		ans.pb(x - mn + 1);
	}

	cout << ans.size() << endl;
	rep(i, ans.size()) cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');

	return 0;
}