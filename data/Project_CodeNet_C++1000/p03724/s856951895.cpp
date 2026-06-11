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
	int n, m;
	cin >> n >> m;
	vector<int> res(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		res[a]++; res[b]++;
	}
	bool ok = true;
	rep(i, n) if (res[i] % 2 == 1) ok = false;
	if (ok) printf("%s\n", "YES");
	else printf("%s\n", "NO");
	return 0;
}
