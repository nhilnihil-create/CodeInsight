#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
constexpr auto INF = INT_MAX / 2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n, l;
	cin >> n >> l;
	vi a(n);
	rep(i, n)cin >> a[i];

	int k = 0;
	rep1(i, n - 1)if (a[i - 1] + a[i] >= l)k = i;

	if (k == 0) {
		cout << "Impossible" << endl;
		return 0;
	}

	vi ans(0);

	while (k > 0) {
		ans.push_back(k);
		k--;
	}
	k = ans[0] + 1;
	while (k < n) {
		ans.push_back(k);
		k++;
	}

	cout << "Possible" << endl;
	rep(i, n - 1)cout << ans[n - 2 - i] << endl;

}