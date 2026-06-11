#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORd(i, a, b) for (int i = (a) ; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define sp system("pause")
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
const int N = (int) 1e5 + 10;
void TimeExecution() {
    cout << "\n\n===>> Time Execution: " << clock() / (double)1000 << " sec(s).";
}
int t;
int n;
int a[N];
int cnt[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    /*
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    */
    bool ok = 1;
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n)
    {
        int x = ((n - 1) + a[i]) / 2;
        int y = ((n - 1) - a[i]) / 2;
        cnt[x + 1]++;
        cnt[y + 1]++;
        if(cnt[x + 1] > 2 || cnt[y + 1] > 2) ok = 0;
    }
    ll res = 1;
    FOR(i, 1, n / 2)
    {
        if(cnt[i] == 1)
        {
            res = (res * 4) % MOD;
        }
        if(cnt[i] == 2)
        {
            res = (res * 2) % MOD;
        }
       /// cout << cnt[i] << " ";
    }
    if(ok) cout << res;
    else cout << 0;
    return 0;
}
