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
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n;
	cin >> n;
	vi a(n);
	rep(i, n)cin >> a[i];

	ll ans = a[0] - 1;
	int k = 2;
	rep1(i, n - 1) {
		if (a[i] == k)k++;
		if (a[i] <= k)continue;
		ans += (a[i] - 1) / k;
	}

	cout << ans << endl;
	
}