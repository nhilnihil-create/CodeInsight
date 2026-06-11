#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 5050, mod = 1e9 + 7;
int s[maxn][maxn], q[maxn][maxn], bp[15][maxn], res[maxn], tmp[maxn], n;
void add(int &a, int b) {
	a += b;
	if(a >= mod) a -= mod;
}
void mul(int *a, int *b, int *c) {
	for(int i = 0; i <= n; i++)
		for(int j = 0; i + j <= n; j++)
			add(c[i+j], a[i]*1ll*b[j]%mod);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	string st; cin >> st;
	s[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			add(s[i+1][j+1], s[i][j]*2ll%mod);
			add(s[i+1][max(0, j-1)], s[i][j]);
		}
	}
	q[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			add(q[i+1][j+1], q[i][j]*2ll%mod);
			if(j) add(q[i+1][j-1], q[i][j]);
		}
	}
	for(int i = 0; i <= n; i++) bp[0][i] = q[i][0];
	for(int i = 1; i < 15; i++) mul(bp[i-1], bp[i-1], bp[i]);
	res[0] = 1;
	for(int x = st.size(),i = 0; i < 13; i++) {
		if(!((x>>i)&1)) continue;
		memset(tmp, 0, sizeof tmp);
		mul(res, bp[i], tmp);
		for(int i = 0; i <= n; i++) swap(res[i], tmp[i]);
	}
	int ans = 0;
	for(int i = 0; i <= n-st.size(); i++) {
		add(ans, res[i]*1ll*s[n-st.size()-i][0]%mod);
	}
	cout << ans << '\n';
}
