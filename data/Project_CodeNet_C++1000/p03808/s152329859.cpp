#include <algorithm>
#include <bitset>
#include <cfloat>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps DBL_EPSILON
#define mod (ll)998244353
#define INF LLONG_MAX/10
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int n, a[100010], b[100010], sum;
signed main() {
	cin >> n;
	rep(i, n) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % (n * (n + 1) / 2)) {
		puts("NO");
		return 0;
	}
	sum /= n * (n + 1) / 2;
	rep(i, n - 1)b[i] = a[i + 1] - a[i] - sum;
	b[n - 1] = a[0] - a[n - 1] - sum;
	rep(i, n) {
		if (b[i] > 0 || b[i] % n) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}