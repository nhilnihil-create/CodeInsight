#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define FOR(i, a, b) for(int i=a, _n=b; i<=_n; ++i)
using namespace std;

const int N = 1e5+5, open = -1e7, close = 1e7;
int n, m, ans[N], bit[N];
vector<pair<int, int> > qu;

void update(int i, int x)
{
    for(; i>0; i-=i&-i) bit[i] += x;
}
int get(int i)
{
    int res =0 ; for(; i<=m; i+=i&-i)
    res += bit[i]; return res;
}
int main()
{
    ios::sync_with_stdio(); cin.tie(0);
    ///freopen("a.inp","r",stdin);

    cin >> n >> m;
    FOR(i, 1, n) {
        int l, r; cin >> l >> r;
        FOR(j, 2, sqrt(m)) if (l <= r/j*j) ans[j] += 1;
        qu.pb(mp(l, open));
        qu.pb(mp(r, close+l));
    }
    FOR(j, sqrt(m)+1, m) for(int x=j; x<=m; x+=j) qu.pb(mp(x, j));

    sort(qu.begin(), qu.end());
    FOR(i, 0, qu.size()-1)
    if (qu[i].y == open) {
        update(qu[i].x, 1);
    } else
    if (qu[i].y > close) {
        update(qu[i].y-close, -1);
    } else {
        ans[qu[i].y] += get(qu[i].x-qu[i].y+1);
    }

    ans[1] = n;
    FOR(i, 1, m) cout << ans[i] << '\n';
}
