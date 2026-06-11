#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <iomanip>
#include <string>
#include <queue>
#include <numeric>
#include <functional>
#include <array>
#include <map>
#include <set>

#define INF 1000000007 //1000000000000000003
#define MOD 1000000007

#define ll long long

//printf("%.10f", );

using namespace std;
using P = pair<int, int>;
using T = tuple<int, int, int>;
using edge = struct { int to; long long dist; };

vector<edge>tree[100010];
vector<P> connect[100005];
long long cost[100005];

long long dp[55][55];

bool compare_by_second(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {

	int N, A, B;
	cin >> N >> A >> B;

	vector<ll> v(N);
	map<ll, int>vm;
	ll before = 0;
	bool isSame = true;
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
		if (i != 0 && before != v[i])isSame = false;
		before = v[i];
		vm[v[i]]++;
	}

	dp[0][0] = 1;
	for (int n = 1; n <= N; n++) {
		for (int k = 0; k <= n; k++) {
			if (k - 1 >= 0) {
				dp[n][k] = dp[n - 1][k - 1] + dp[n - 1][k];
			}
			else {
				dp[n][k] = dp[n - 1][k];
			}
		}
	}

	long double heikin = 0;
	ll ans = 0;
	if (isSame) {
		heikin = (long double)v.back();
		for (int i = A; i <= B; ++i) {
			ans += (ll)dp[N][i];
		}
	}
	else {
		ll sum = 0;
		map <ll, int > m;
		sort(v.begin(), v.end());
		isSame = true;
		int a = A;
		for (int i = N - 1; N - B <= i; --i) {
			sum += v[i];
			long double next = ((long double)sum) / ((long double)(N - i));
			if (0 < a || heikin <= next) {
				if (i != N - 1 && before != v[i]) {
					isSame = false;
				}
				m[v[i]]++;
				heikin = next;
				a--;
				before = v[i];
			}
			else break;
		}

		if (isSame) {
			for (auto ma : m) {
				for (int i = A; i <= ma.second;++i) {
					if (vm[ma.first] < i)break;
					ans += (ll)dp[vm[ma.first]][i];
				}
			}
		}
		else {
			ans = 1;
			for (auto ma : m) {
				ans *= dp[vm[ma.first]][ma.second];
			}
		}
	}

	cout << fixed << setprecision(10) << heikin << endl;
	cout << ans << endl;
}