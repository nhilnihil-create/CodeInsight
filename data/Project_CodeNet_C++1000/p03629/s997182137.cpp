#include"bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
typedef pair<int, int> P;
const long long mod = 1000000007;
const int L = 26;
int rwa[26][200006];
int nxt[26][200006];
int jump[200006];//iから始めたときの終わり
int dp[200006];
signed main() {
	string s; cin >> s;
	int n = s.size();
	rep(i, L)rep(j, n)nxt[i][j] = n;
	rep(i, n) {
		rwa[s[i] - 'a'][i + 1]++;
		nxt[s[i] - 'a'][i] = i;
	}
	rep(i, n)rep(j, L)rwa[j][i + 1] += rwa[j][i];
	rep(i, L) {
		for (int j = n - 1; j > 0; j--) {
			nxt[i][j - 1] = min(nxt[i][j - 1], nxt[i][j]);
		}
	}
	rep(i, n) {
		int l = i-1, r = n;
		int c = 0;
		while (r - l > 1) {
			int mi = (r + l) / 2;
			rep(j, L) {
				if (rwa[j][mi+1] - rwa[j][i])c++;
			}
			if (c==L)r = mi;
			else l = mi;
			c = 0;
		}
		rep(j, L)if (rwa[j][r] - rwa[j][i])c++;
		if(c==L)jump[i] = l;
		else jump[i] = r;
	}
	dp[n] = 1;
	for (int i = n - 1; i >= 0; i--)dp[i] = dp[jump[i]+1] + 1;

	string ans;
	int now = 0;
	while (now < n) {
		rep(j, L) {
			int nn = nxt[j][now];
			if (dp[nn+1] + 1 + ans.size() == dp[0]) {
				ans.push_back('a' + j); 
				now = nn + 1;
				break;
			}
		}
	}
	cout << ans << endl;
}