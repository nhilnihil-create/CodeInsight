#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define lcm( a, b ) (a)/__gcd((a),(b))*(b)
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair< int, int > P;
typedef pair< LL, LL > LP;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1000000007;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

LL fac[SIZE], finv[SIZE], inv[SIZE];
void combInit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for( int i = 2; i < SIZE; ++i ) {
        fac[i] = (fac[i - 1] * i) % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = (finv[i - 1] * inv[i]) % MOD;

    }
}

LL comb(int n, int k) {
    if( n < k ) return 0;
    if( n < 0 || k < 0 ) return 0;
    return (fac[n] * (finv[k] * finv[n - k] % MOD)) % MOD;

}

vector< int > Div( int n ) {
    vector< int > ret;
    for( int i = 1; i * i <= n; ++i ) {
        if( n % i == 0 ) {
            ret.pb( i );

            if( i * i != n ) ret.pb( n / i );
        }
    }
    sort( all( ret ) );
    return ret;
}

bool Solve(int pos);

int n, k;
vector< int > v;
bool dp[5005][5005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for( int i = 0; i < n; ++i ) {
        int a;
        cin >> a;
        v.pb(a);

    }
    sort(all(v));

    int l, r;
    l = -1; r = n;
    while( r - l > 1 ) {
        int mid = (l + r) / 2;
        bool need = Solve(mid);

        if( need ) {
            r = mid;

        } else {
            l = mid;

        }
    }
    cout << l + 1 << endl;

    return 0;
}

bool Solve(int pos) {
    for( int i = 0; i < n; ++i ) {
        for( int j = 0; j <= k; ++j ) {
            dp[i][j] = false;

        }
    }

    for( int i = 0; i < n; ++i ) {
        dp[i][0] = true;
        if( i == 0 && i == pos ) continue;

        for( int j = 1; j < k; ++j ) {
            if( i == pos ) {
                dp[i][j] = dp[i - 1][j];
                continue;

            }

            if( i == 0 ) {
                if( v[i] == j ) {
                    dp[i][j] = true;

                }
            } else {
                if( v[i] <= j ) {
                    dp[i][j] |= dp[i - 1][j - v[i]];

                }
                dp[i][j] |= dp[i - 1][j];
            }
        }
    }

    for( int j = max(k - v[pos], 0); j < k; ++j ) {
        if( dp[n - 1][j] ) {
            return true;

        }
    }
    return false;
}

