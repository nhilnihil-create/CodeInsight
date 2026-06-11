#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
char s[maxn];
int c[maxn][26];
int min_from[maxn];
int vis[maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> s + 1, n = strlen(s + 1);
	for(int j = 0;j < 26;++j) c[n + 1][j] = n + 1;
	for(int i = n;i >= 0;--i) {
		for(int j = 0;j < 26;++j) c[i][j] = c[i + 1][j];
		if(i != n) c[i][s[i + 1] - 'a'] = i + 1;
	}
	std::queue<int> q;
	q.push(0); vis[0] = 1;
	for(;!q.empty();) {
		int x = q.front(); q.pop();
		for(int j = 0;j < 26;++j) {
			if(!vis[c[x][j]]) {
				vis[c[x][j]] = 1;
				min_from[c[x][j]] = x;
				q.push(c[x][j]);
			}
		}
	}
	std::string ans;
	for(int i = 0;i < 26;++i) if(c[min_from[n + 1]][i] == n + 1) { ans = char(i + 'a'); break; }
	for(int i = n + 1;i = min_from[i];) ans += s[i];
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}
