#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
typedef char AC[20][maxn];
int q;
char s[maxn], t[maxn];
AC bz0, bz1;
inline int get(char x,char y){ 
	if(!x || !y) return x | y;
	return x == y ? x == 'A' ? 'B' : 'A' : 0;
}
inline std::string get(int l,int r, const AC & bz) {
	std::string ret = {bz[0][l]};
	++ l; int R = 0;
	for(int i = 19;i >= 0;--i) {
		if(l + (1 << i) - 1 <= r) {
			R = get(R, bz[i][l]), l += 1 << i;
		}
	}
	if(R) ret += char(R);
	if(ret.size() == 2 && ret[0] == ret[1]) ret = get(ret[0], ret[1]);
	return ret;
}
inline bool chk(std::string s0, std::string s1) {
	if(s0.size() == 1 || s1.size() == 1) return s0 == s1;
	return s0.size() == s1.size();
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> s + 1 >> t + 1;
	int n = strlen(s + 1), m = strlen(t + 1);
	rep(i, 1, n) bz0[0][i] = s[i];
	rep(i, 1, 20) for(int j = 1;j + (1 << i) - 1 <= n;++j) bz0[i][j] = get(bz0[i - 1][j], bz0[i - 1][j + (1 << i - 1)]);
	rep(i, 1, m) bz1[0][i] = t[i];
	rep(i, 1, 20) for(int j = 1;j + (1 << i) - 1 <= m;++j) bz1[i][j] = get(bz1[i - 1][j], bz1[i - 1][j + (1 << i - 1)]);
	cin >> q;
	rep(i, 1, q) {
		int l0, r0, l1, r1;
		cin >> l0 >> r0 >> l1 >> r1;
		cout << (chk(get(l0, r0, bz0), get(l1, r1, bz1)) ? "YES" : "NO") << '\n';
	}
}
