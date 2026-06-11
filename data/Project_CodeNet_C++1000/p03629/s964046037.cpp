#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

int dp[N], nxt[N][26], tran[N];

signed main()
{
	IO_OP;
	
	string s;
	cin >> s;
	for(int j = 0; j < 26; j++) nxt[s.size()][j] = s.size();
	for(int i = s.size() - 1; i >= 0; i--) {
		for(int j = 0; j < 26; j++) nxt[i][j] = nxt[i + 1][j];
		nxt[i][s[i]-'a'] = i;
	}
	for(int i = s.size() - 1; i >= 0; i--) {
		dp[i] = INF;
		for(int j = 0; j < 26; j++) {
			int cur = dp[nxt[i + 1][j]] + 1;
			if(dp[i] > cur) {
				dp[i] = cur;
				tran[i] = j;
			}
		}
	}
	int mn = INF, st;
	for(int j = 0; j < 26; j++) {
		int cur = dp[nxt[0][j]] + 1;
		if(cur < mn) {
			mn = cur;
			st = j;
		}
	}
	string t;
	int pos = -1;
	for(int i = 0; i < mn; i++) {
		t.PB('a' + st);
		pos = nxt[pos + 1][st];
		st = tran[pos];
	}
	cout << t << endl;
}



