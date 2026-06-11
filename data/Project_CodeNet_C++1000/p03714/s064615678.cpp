#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<functional>
#include<iomanip>
#include<queue>
#include<cassert>
#include<tuple>
#include<set>
#include<map>
#include<list>
#include<bitset>

#define PB push_back
#define ALL(a)  (a).begin(),(a).end()
#define all(v) begin(v), end(v)
#define DWN(a)  (a).begin(),(a).end(), greater<int>()
#define rep(i, m) for (int i = 0; i < m; i++)
#define REP(i, n, m) for (int i = n; i < m; i++)

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const int INF = (int)1e9;
const ll MOD{ (ll)1e9 + 7 };

int n;
int a[300010];
priority_queue<ll, vector<ll>, greater<ll>> pq1;
priority_queue<ll> pq2;
ll sum1 = 0, sum2 = 0;
ll dp1[300010], dp2[300010];
ll ans = -1e18;

int main() {
	cin >> n;
	for(int i = 0; i < 3 * n; i++) {
		cin >> a[i];
		if (i < n) {
			pq1.push(a[i]);
			sum1 += a[i];
		}
		if(i >= 2 * n) {
			pq2.push(a[i]);
			sum2 += a[i];
		}
	}
	for(int i = n; i <= 2 * n; i++) {
		dp1[i] = sum1;
		sum1 += a[i];
		pq1.push(a[i]);
		sum1 -= pq1.top();
		pq1.pop();
	}
	for (int i = 2 * n - 1; i >= n - 1; i--) {
		dp2[i] = sum2;
		sum2 += a[i];
		pq2.push(a[i]);
		sum2 -= pq2.top();
		pq2.pop();
	}
	for (int i = n; i <= 2 * n; i++) {
		ans = max(ans, dp1[i] - dp2[i - 1]);
	}
	cout << ans << endl;
	return 0;
}