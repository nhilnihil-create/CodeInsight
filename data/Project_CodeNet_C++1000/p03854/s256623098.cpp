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

string ds[4] = {"erase", "eraser", "dream", "dreamer"};

void solve() {
	string s;
	cin >> s;
	reverse(ALL(s));
	int n = s.size();
	int l = 0;
	for (;;) {
		if (l == n) {
			cout << "YES" << endl;
			return;
		}
		if (s[l] != 'r') {
			if (n - l < 5) {
				cout << "NO" << endl;
				return;
			}
			string t = s.substr(l, 5);
			reverse(ALL(t));
			if (t != "dream" && t != "erase") {
				cout << "NO" << endl;
				return;
			}
			l += 5;
		} else {
			if (n - l < 6) {
				cout << "NO" << endl;
				return;
			}
			string t = s.substr(l, 6);
			reverse(ALL(t));
			if (t != "eraser") {
				if (n - l < 7) {
					cout << "NO" << endl;
					return;
				}
				t = s.substr(l, 7);
				reverse(ALL(t));
				if (t != "dreamer") {
					cout << "NO" << endl;
					return;
				}
				l += 7;
			} else {
				l += 6;
			}
		}
	}
}

int main() {
	solve();
	return 0;
}