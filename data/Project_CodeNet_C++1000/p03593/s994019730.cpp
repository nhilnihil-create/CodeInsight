#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H, W;
	cin >> H >> W;
	vector<string> a(H);
	int memo[26] = {0};
	REP(i, H) {
		cin >> a[i];
		REP(j, W) {
			memo[a[i][j] - 'a']++;
		}
	}
	priority_queue<int> pq;
	REP(i, 26) {
		pq.emplace(memo[i]);
	}
	REP(i, H / 2) {
		REP(j, W / 2) {
			int num = pq.top();
			pq.pop();
			if (num < 4) {
				cout << "No" << endl;
				return 0;
			}
			pq.emplace(num - 4);
		}
	}
	if (H % 2) {
		REP(j, W / 2) {
			int num = pq.top();
			pq.pop();
			if (num < 2) {
				cout << "No" << endl;
				return 0;
			}
			pq.emplace(num - 2);
		}
	}
	if (W % 2) {
		REP(i, H / 2) {
			int num = pq.top();
			pq.pop();
			if (num < 2) {
				cout << "No" << endl;
				return 0;
			}
			pq.emplace(num - 2);
		}
	}
	cout << "Yes" << endl;

	return 0;
}