#include<bits/stdc++.h>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;

template <typename tn> void read (tn & a) {
	tn x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9'){ if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9'){ x = x * 10 + c - '0'; c = getchar(); }
	a = f == 1 ? x : -x;
}

const int MAXN = 1e5 + 10;

int fa[MAXN],x[MAXN];
bool k[MAXN],s[MAXN];
int n, m;
ll i, l, r, t, cnt;
ll ans;

int find (int xx) {
    if (!fa[xx]) return xx;
    int t = find(fa[xx]);
    x[xx] ^= x[fa[xx]];
    return fa[xx] = t;
}

int main(){
	read(n);
	read(m);
    rep(i, 1, m) {
    	int u, v;
    	read(u);
    	read(v);

        k[u] = 1;
		k[v] = 1;

        l = find(u); 
		r = find(v);
        if (l < r) {
            swap(l,r);
            swap(u,v);
        }
        if (l == r && x[u] == x[v]) {
			s[l] = 1;
		}
        if (l == r) continue;
        s[r] |= s[l];
        fa[l] = r;
        x[l] = x[u] ^ x[v] ^ 1;
    }
    rep(i, 1, n) if (!k[i]) {
		cnt++;
	}
    ans = (ll)cnt * (n - cnt) * 2 + (ll)cnt * cnt;
    cnt = 0;
    rep(i, 1, n) if (k[i]&&!fa[i]) {
		cnt++;
	}
    ans += (ll)cnt * cnt;
    cnt = 0;
    rep(i, 1, n) if (k[i] && !fa[i] && !s[i]) cnt++;
    rep(i, 1, n) if (k[i] && !fa[i] && !s[i]) ans += (ll)cnt;
	cout << ans << "\n";
	return 0;
}