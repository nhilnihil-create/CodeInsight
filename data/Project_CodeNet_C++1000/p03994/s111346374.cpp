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
	string s;
	cin >> s;
	int k;
	cin >> k;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (k == 0) break;
		char c = s[i];
		if (c == 'a') continue;
		if ('z' - c + 1 <= k) {
			k -= 'z' - c + 1;
			s[i] = 'a';
		}
	}
	if (k != 0) {
		s[n-1] = s[n-1] + (k % 26);
	}
	cout << s << endl;
}

int main() {
	solve();
	return 0;
}