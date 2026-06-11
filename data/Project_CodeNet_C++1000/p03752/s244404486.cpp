#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl;

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100010;

int main() {
//	cout << fixed << setprecision(15);
	int n, k;
	cin >> n >> k;
	vll a(n);
	rep(i, n) cin >> a[i];

	ll ans = INFL;
	rep(i, 1 << n) {
		if(__builtin_popcount(i) < k) continue;
		ll _ans = 0;
		ll last_a = 0;
		rep(j, n) {
			if(i & (1 << j) && last_a >= a[j]) {
				_ans += last_a - a[j] + 1;
				last_a++;
			}
			else {
				last_a = max(a[j], last_a);
			}
		}
		ans = min(_ans, ans);
	}
	cout << ans << endl;
}
