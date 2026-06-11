#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()

constexpr auto INF = INT_MAX/2;
constexpr auto MOD = 1000000007;


int main() {

	int n;
	cin >> n;
	vi a(n);
	rep(i, n)cin >> a[i];

	ll ans = a[0] / 2;
	a[0] -= (a[0] / 2) * 2;

	rep(i, n - 1) {
	
		if (a[i]&&a[i+1]) { a[i]--; a[i + 1]--; ans++; }
		ans += a[i + 1] / 2;
		a[i + 1] -= (a[i + 1] / 2) * 2;

	}

	cout << ans << endl;

}