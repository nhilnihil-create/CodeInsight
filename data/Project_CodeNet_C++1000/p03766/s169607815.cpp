//     _
//   _/_\_
//   (O_o)
//  ~(   )~
//   (~~~)
//   /   \

#include <bits/stdc++.h>

#define left nadnlassad
#define right asdaslknd
#define y1 kjdajasjdsas
#define nxt accepted
#define prev why_would_you_call_when_you_are_high

#define pb push_back
#define mp make_pair
#define mt make_tuple

#define f first
#define s second

#define ll long long
#define ld long double
#define ull unsigned ll

#define hash_t pair<ll, ull>
#define pii pair<int, int>
#define uint unsigned int
#define puu pair<uint, uint>

#define sqr(x) ((x) * 1LL * (x))

#define vec vector<int>
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define endl "\n"
#define bits(x) __builtin_popcountll(x)
#define forn(i, s, t) for(int i = (int) s; i <= (int) t; i++)
#define form(i, t, s) for(int i = (int) t; i >= (int) s; i--)

using namespace std;

void rf() {
    #define fname "sparse"
    #ifdef SONY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(fname".in", "r", stdin);
        //freopen(fname".out", "w", stdout);
    #endif //SONY
}

const int nx[8] = {2, -2, -2, 2, 1, 1, -1, -1};
const int ny[8] = {1, 1, -1, -1, 2, -2, -2, 2};
const int Nx[4] = {0, 0, -1, 1};
const int Ny[4] = {1, -1, 0, 0};

const ll LINF = (ll) 5e18;
const int INF = 1e9 + 7;

const int N = 6e5 + 1;
const int MAXN = 3e6 + 1;
const double EPS = 1e-9, PI = 3.14159265359;

inline int get_int() {
    char x = getchar();
    int ret = 0;
    bool neg = 0;
    while (!('0' <= x && x <= '9')) {
        if (x == '-')
            neg = 1;
        x = getchar();
    }
    while ('0' <= x && x <= '9') {
        ret = ret * 10 + x - '0';
        x = getchar();
    }
    if (neg) ret *= -1;
    return ret;
}

int n;
int dp[MAXN], suff[MAXN];

int add(int x, int y) {
    x += y;
    if (x >= INF) x -= INF;
    if (x < 0) x += INF;
    return x;
}

int main() {
    srand(time(0));
    //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //rf();
    ld beg = clock();
    cin >> n;
    forn (i, n + 1, n * 3) dp[i] = 1;
    dp[n] = n;
    form (i, n * 3, n) {
        suff[i] = add(suff[i + 1], dp[i]);
    }
    form (i, n - 1, 1) { 
        int ans = dp[i + 1];
        ans = add(ans, (n - 1) * 1ll * (n - 1) % INF);
        ans = add(ans, add(suff[i + 3], -suff[i + n + 2]));
        dp[i] = ans;
        suff[i] = add(suff[i + 1], dp[i]);
    }
    cout << dp[1];
    #ifdef SONY
        fprintf(stderr, "\n%.6f", (double) (clock() - beg) / CLOCKS_PER_SEC);
    #endif //SONY
    return 0;
}