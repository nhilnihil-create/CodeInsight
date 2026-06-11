#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(100001);
	rep(i, n) {
		int b; cin >> b;
		a[b]++;
	}
	int ans = 0;
	for (auto& c : a) if (c > 0) ans++;
	dunk(ans % 2 == 0 ? ans - 1 : ans);
	return 0;
}