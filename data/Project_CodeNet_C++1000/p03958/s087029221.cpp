#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;

#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
constexpr auto INF = 1050000000;
constexpr auto MOD = 1000000007;

int main() {
	int k, t;
	cin >> k >> t;
	vi a(t);
	rep(i, t)cin >> a[i];
	sort(all(a));
	int ans = 0;
	if (t == 1)ans = k - 1;
	else {
		int other = 0;
		rep(i, t - 1)other += a[i];
		ans = a[t - 1] - other - 1;
		if (ans < 0)ans = 0;
	}

	cout << ans << endl;
}