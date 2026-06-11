#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n;
	cin >> n;
	vi a(n);
	rep(i, n)cin >> a[i];
	sort(all(a));

	if (a[n - 1] - a[0] > 1) {
		cout << "No" << endl;
	}
	else if (a[0] == a[n - 1]) {
		if (a[0] == n - 1) {
			cout << "Yes" << endl;
		}
		else if (a[0] <= n / 2) {
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}
	else {
		int k = upper_bound(all(a), a[0]) - a.begin();
		int l = n - k;
		if (1 <= a[n - 1] - k && a[n - 1] - k <= l / 2) {
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}

}