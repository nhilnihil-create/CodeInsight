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
	ll n, k;
	cin >> n >> k;
	vector<ll> cnt(100005);
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		cnt[a] += b;
	}
	rep(i, 100005) {
		if (k - cnt[i] <= 0) {
			printf("%d\n", i);
			return 0;
		}
		else {
			k -= cnt[i];
		}
	}
	return 0;
}
