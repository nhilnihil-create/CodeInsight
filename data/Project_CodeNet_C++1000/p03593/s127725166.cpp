#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	int h, w;
	cin >> h >> w;
	vector<string> v(h);
	rep(i,h) cin >> v[i];
	vector<int> cnt(26);
	rep(i,h) rep(j,w) cnt[v[i][j] - 'a']++;
	priority_queue<int> q;
	rep(i,26) q.push(cnt[i]);
	int p = 0;
	for (int i = 0; i < (h / 2) * (w / 2); i++) {
		int t = q.top(); q.pop();
		if (t >= 4) {
			t -= 4;
			q.push(t);
		} else {
			cout << "No" << endl;
			return;
		}
	}
	if (h % 2 == 0 && w % 2 == 0) {
		cout << "Yes" << endl;
	} else {
		if (h % 2 == 1 && w % 2 == 1) {
			bool flag = 0;
			while (!q.empty()) {
				int t = q.top(); q.pop();
				if (t % 2 == 1) {
					if (flag) {
						cout << "No" << endl;
						return;
					}
					flag = 1;
				}
			}
			if (flag) cout << "Yes" << endl;
			else cout << "No" << endl;
		} else {
			while(!q.empty()) {
				int t = q.top(); q.pop();
				if (t % 2 == 1) {
					cout << "No" << endl;
					return;
				}
			}
			cout << "Yes" << endl;
		}
	}
}

int main() {
	solve();
	return 0;
}