#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define int long long
using namespace std;

int n, k;
int ans = 0;
int psum[200005];
int tree[800005];
ii tmp[200005];

void upd(int id, int l, int r, int i)
{
    if (i < l || i > r)
        return;
    if (l == r)
    {
        if (l == i)
            tree[id]++;
        return;
    }

    int mid = (l + r) / 2;
    upd(id*2, l, mid, i);
    upd(id*2 + 1, mid+1, r, i);
    tree[id] = tree[id*2] + tree[id*2 + 1];
}

int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
        return 0;

    if (u <= l && r <= v)
        return tree[id];

    int mid = (l + r) / 2;
    return get(id*2, l, mid, u, v) + get(id*2 + 1, mid+1, r, u, v);
}

void compress()
{
    int last = 1e18, cnt = 0;
    sort(tmp, tmp + n + 1);
    for (int i = 0; i <= n; i++)
    {
        if (last != tmp[i].fi)
        {
            cnt++;
            last = tmp[i].fi;
        }
        psum[tmp[i].se] = cnt;
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    freopen("depart.inp", "r", stdin);
//    freopen("depart.out", "w", stdout);

    cin >> n >> k;
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        psum[i] = psum[i-1] + x - k;
        tmp[i].fi = psum[i];
        tmp[i].se = i;
    }
    compress();

    for (int i = 0; i <= n; i++)
    {
        ans += get(1, 0, n, 0, psum[i]);
        upd(1, 0, n, psum[i]);
    }
    cout << ans;
}
