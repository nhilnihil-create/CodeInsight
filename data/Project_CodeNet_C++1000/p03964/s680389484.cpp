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

ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b; 
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N; cin >> N;
    vl T(N), A(N); REP(i, N) cin >> T[i] >> A[i];

    for(int i = 1; i < N; i++)
    {
        ll x = max((T[i-1]+T[i]-1)/T[i], (A[i-1]+A[i]-1)/A[i]);
        T[i] *= x;
        A[i] *= x;
    }

    cout << T[N-1]+A[N-1] << endl;
}