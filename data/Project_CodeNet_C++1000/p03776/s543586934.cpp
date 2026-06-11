#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD (1000000007)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
typedef long long ll;
typedef unsigned long long ull;

ll v[50];
ll combination[51][51];

int main()
{
	int N, A, B;
	ll ans = 0, vthr;
	double avg = 0;
	map<ll, int> cnt, inner_cnt;

	cin >> N >> A >> B;
	rep(i, N) {
		cin >> v[i];
		if (cnt.count(v[i]) == 0) cnt[v[i]] = 1;
		else cnt[v[i]]++;
	}

	sort(v, v + N, greater<ll>());

	repc(n, 1, N) {
		repc(r, 0, n) {
			if (r == 0 || r == n) combination[n][r] = 1;
			else combination[n][r] = combination[n - 1][r - 1] + combination[n - 1][r];
		}
	}

	repc(i, A, B) {
		ll add = 1;
		map<ll, bool> checked;

		if (i == A) {
			ll sum = 0;

			rep(j, i) {
				sum += v[j];
				if (inner_cnt.count(v[j]) == 0) inner_cnt[v[j]] = 1;
				else inner_cnt[v[j]]++;
			}
			avg = (double)sum / (double)i;

			vthr = v[0];
		}
		else {
			if (v[i - 1] < vthr) break;
			inner_cnt[v[i - 1]]++;
		}

		rep(j, i) {
			if (checked.count(v[j]) >= 1) continue;

			add *= combination[cnt[v[j]]][inner_cnt[v[j]]];
			checked[v[j]] = true;
		}
		ans += add;
	}

	printf("%.10lf\n", avg);
	cout << ans << endl;

	return 0;
}