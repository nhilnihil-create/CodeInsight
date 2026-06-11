#include <bits/stdc++.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define ALL(v) (v).begin(), (v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x, n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<ll,ll> P;   
typedef pair<ll,P> PP;

//-----------------------------------------------------------------------------

string s;
int len[200010], nxt[200010][26];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

	cin >> s;
	int sz = (int)s.size();
	len[0] = -1;
	for (int i = sz; i > 0; i--) {
		for (int j = 0; j < 26; j++) {
			nxt[i][j] = nxt[i+1][j];
		}
		nxt[i][s[i-1] - 'a'] = i + 1;
		int mi = INF;
		for (int j = 0; j < 26; j++) {
			mi = min(mi, len[nxt[i][j]]);
		}
		len[i] = mi + 1;
		//cout << "len = " << mi + 1 << " nxt = ";
		//REP(j, 26) cout << nxt[i][j] << ' ';
		//cout << endl;
	}
	int idx = 1;
	while (idx) {
		int j = 0;
		while (len[nxt[idx][j]] != len[idx] - 1) j++;
		cout << (char)('a' + j);
		//cout << "idx, j = " << idx << ',' << j << endl;
		idx = nxt[idx][j];
	}
	cout << endl;
  
    return 0;
}
