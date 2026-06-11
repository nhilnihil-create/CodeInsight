#include <bits/stdc++.h>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
    if (a > b) a = b;
}

template<class T, class U>
void ckmax(T &a, U b)
{
    if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const int MAXN = 100013;

int N, L, T;
pii arr[MAXN];
bool hasl, hasr;
pii ans[MAXN];
vpi pos;

bool cmp(pii a, pii b)
{
    if (a.fi != b.fi)
    {
        return a.fi < b.fi;
    }
    return a.se > b.se;
}
int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    cin >> N >> L >> T;
    pii lol;
    FOR(i, 0, N)
    {
        cin >> arr[i].fi >> arr[i].se;
        if (arr[i].se == 2) arr[i].se = -1;
        int ft = arr[i].fi + arr[i].se * T;
        ft %= L;
        if (ft < 0) ft += L;
        ans[i] = {ft, arr[i].se};
        if (i == 0) lol = ans[i];
    }
    int idx = 0;
    if (arr[0].se == 1)
    {
        FOR(j, 1, N)
        {
            if (arr[j].se == 1) continue;
            //count the # these guys intersect.
            int d = arr[j].fi - arr[0].fi;
            ll k = max(0ll, (2ll * T - d + L)) / L;
            idx += k;
            idx %= N;
            // cerr << 2 * T - d + L << '/' << L << endl;
            //d/2, (d+L)/2,....(d+(k-1)L)/2
            //(d + (k-1)L) / 2 <= T -> d+(k-1)L <= 2T => (2T - d + L)/L >= k
        }
        // cerr << idx << " intersectons\n";
        sort(ans, ans + N);
        FOR(i, 0, N) if (ans[i] == lol) idx = i - idx;
        if (idx < 0) idx += N;
        //the ith is ant #idx
        //so i-idx ant #0
        //val[idx1] corresponds to idx
    }
    else
    {
        FOR(j, 1, N)
        {
            if (arr[j].se == -1) continue;
            int d = arr[0].fi + L - arr[j].fi;
            ll k = max(0ll, (2ll * T - d + L)) / L;
            idx += k;
            idx %= N;
        }
        sort(ans, ans + N);
        //the ith is ant #-idx
        //so the i+idx is ant #0
        FOR(i, 0, N) if (ans[i] == lol) idx = i + idx;
        if (idx > N) idx -= N;
    }
    rotate(ans, ans + idx, ans + N);
    FOR(i, 0, N)
    {
        cout << ans[i].fi << '\n';
    }
    return 0;
}
