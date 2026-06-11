#include <bits/stdc++.h>
#define ll long long
#define maxn 100005
#define F first
#define S second
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define VanLoi "a"
#define gb(i, j) ((i >> j) & 1)
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int, int>
#define Block 400

using namespace std;

int n, vt[maxn], dem[maxn], tg[maxn], mi = 1e9;
ll res[maxn], sl = 0;
pii a[maxn], e[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   // freopen(VanLoi".inp", "r", stdin);
   // freopen(VanLoi".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) {
        cin >> e[i].F;
        e[i].S = i;
    }
    sort(e + 1, e + n + 1);
    int j = 0;
    fi(i, 1, n) {
        if (e[i].F != e[i - 1].F) j++;
        a[e[i].S].F = j;
        a[e[i].S].S = e[i].F;
    }
    fi(i, 1, n) {
        dem[a[i].F]++;
        if (vt[a[i].F] == 0) vt[a[i].F] = i;
    }
    fi(i, 1, n) tg[i] = a[i].F;
    sort(tg + 1, tg + n + 1);
    sl = dem[tg[n]];
    fid(i, n - 1, 0) if (tg[i] != tg[i + 1]) {
        int l = vt[tg[i + 1]], r = vt[tg[i]];
        mi = min(mi, l);
        res[mi] += 1ll * (a[l].S - a[r].S) * sl;
        sl += dem[tg[i]];
    }
    fi(i, 1, n) cout << res[i] << '\n';
    return 0;
}
