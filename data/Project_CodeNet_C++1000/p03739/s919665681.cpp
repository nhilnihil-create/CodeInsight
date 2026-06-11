#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> P;
constexpr auto INF = INT_MAX/2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;


int main() {

	int n;
	cin >> n;
	vi a(n);
	rep(i, n)cin >> a[i];

	ll sum = 0;
	ll ans1 = 0, ans2 = 0;
	ll b1 = 0, b2 = 0;

	rep(i, n) {

		sum += a[i];
		ll k = sum + b1;
		ll l = sum + b2;

		if (i % 2 == 0 && k <= 0) { ans1 += -k + 1;b1 += -k + 1; }
		if (i % 2 == 1 && k >= 0) { ans1 += k + 1;b1 -= k + 1; }

		if (i % 2 == 1 && l <= 0) { ans2 += -l + 1;b2 += -l + 1; }
		if (i % 2 == 0 && l >= 0) { ans2 += l + 1;b2 -= l + 1; }
	}

	cout << min(ans1,ans2) << endl;

}