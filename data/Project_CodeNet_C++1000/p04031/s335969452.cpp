#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n; 
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int ans = inf;
	for (int i = -100; i <= 100; ++i) {
		int tmp = 0;
		rep(j, n) tmp += (i - a[j]) * (i - a[j]);
		mins(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}
