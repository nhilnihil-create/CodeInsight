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

    ll n; cin >> n;
    vl a(n); REP(i, n) cin >> a[i];
    ll sum;
    ll cnt;
    ll ans = INFL;

    // + - + ...
    sum = 0;
    cnt = 0;
    REP(i, n)
    {
        sum += a[i];
        if(i % 2 == 0)
        {
            if(sum <= 0)
            {
                cnt += -sum + 1;
                sum = 1;
            }
        }
        else
        {
            if(sum >= 0)
            {
                cnt += sum + 1;
                sum = -1;
            }
        }
    }
    chmin(ans,  cnt);

    // - + - ...
    sum = 0;
    cnt = 0;
    REP(i, n)
    {
        sum += a[i];
        if(i % 2 == 0)
        {
            if(sum >= 0)
            {
                cnt += sum + 1;
                sum = -1;
            }
        }
        else
        {
            if(sum <= 0)
            {
                cnt += -sum + 1;
                sum = 1;
            }
        }
    }
    chmin(ans,  cnt);

    cout << ans << endl;
}