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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ansl = 0;
	int left = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			left++;
		} else {
			if (left == 0) {
				ansl++;
			} else {
				left--;
			}
		}
	}
	int ansr = left;
	rep(i,ansl) cout << '(';
	cout << s;
	rep(i,ansr) cout << ')';
	cout << endl;
}

int main() {
	solve();
	return 0;
}