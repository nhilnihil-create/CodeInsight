#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for(int i = 0; i < (n); i++)
#define REPS(i, n)  for(int i = 1; i <= (n); i++)
#define RREP(i, n)  for(int i = (n)-1; i >= 0; i--)
#define RREPS(i, n) for(int i = (n); i > 0; i--)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define mp make_pair
#define mt make_tuple
#define pb push_back

using ll  = long long;
using pi  = pair<int, int>;
using pl  = pair<ll, ll>;
using vi  = vector<int>;
using vl  = vector<ll>;
using vs  = vector<string>;
using vb  = vector<bool>;
using vvi = vector<vi>;
using vvl = vector<vl>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll  INFL = 1e18;
const double PI = 3.141592653589793;
const double EPS = 1e-9;

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, A, B; cin >> N >> A >> B;
    vector<double> v(N); REP(i, N) cin >> v[i];
    sort(ALL(v));

    double m = v[N-A];
    ll n = upper_bound(ALL(v), m) - lower_bound(ALL(v), m);
    if(v[N-1] == m)
    {
        ll ans = 0;
        for(ll i = A; i <= min(n, B); i++)
        {
            // nCi 
            ll p = 1;
            for(ll j = 1; j <= i; j++)
            {
                p *= n-j+1;
                p /= j; 
            }
            ans += p;
        }
        cout << m << '\n' << ans << endl;
        return 0;
    }

    ll r = A - (v.end() - upper_bound(ALL(v), m));

    ll ans = 1;
    for(ll i = 1; i <= r; i++)
    {
        ans *= n-i+1;
        ans /= i;
    }

    double ave = 0;
    REP(i, A) ave += v[N-i-1];
    ave /= A;

    cout << ave << endl;
    cout << ans << endl;
}