#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
constexpr auto INF = INT_MAX / 2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n, m;
	cin >> n >> m;
	vvi a(n, vi(m));
	rep(i, n)rep(j, m)cin >> a[i][j];

	int ans = n;
	set<int> se;
	se.insert(INF);

	rep(i, m - 1) {

		map<int, int> mp;

		rep(j, n) {
			int k = 0;
			while (true) {
				if (*se.lower_bound(a[j][k])== a[j][k]) { k++;continue; }
				break;
			}
			mp[a[j][k]]++;
		}

		int hoge = 0;
		int piyo = 0;
		for (auto x : mp)if (x.second > hoge) { hoge = x.second;piyo = x.first; }

		ans = min(ans, hoge);
		se.insert(piyo);

	}

	cout << ans << endl;

}