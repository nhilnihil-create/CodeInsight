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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, W;
    cin >> N >> W;
    LL w, u;
    cin >> w >> u;
    vector< LL > v[4];
    v[0].pb(u);

    for( int i = 1; i < N; ++i ) {
        LL a, b;
        cin >> a >> b;
        v[a - w].pb(b);

    }

    for( int i = 0; i < 4; ++i ) {
        sort(all(v[i]), greater< LL >());

    }

    LL res = 0;
    LL w1 = 0, v1 = 0;
    for( int i = 0; i <= v[0].size(); ++i ) {
        if( i != 0 ) {
            ++w1;
            v1 += v[0][i - 1];

        }
        LL w2 = 0, v2 = 0;
        for( int j = 0; j <= v[1].size(); ++j ) {
            if( j != 0 ) {
                ++w2;
                v2 += v[1][j - 1];

            }
            LL w3 = 0, v3 = 0;
            for( int k = 0; k <= v[2].size(); ++k ) {
                if( k != 0 ) {
                    ++w3;
                    v3 += v[2][k - 1];

                }
                LL w4 = 0, v4 = 0;
                for( int l = 0; l <= v[3].size(); ++l ) {
                    if( l != 0 ) {
                        ++w4;
                        v4 += v[3][l - 1];

                    }
                    if( w1 * w + w2 * (w + 1) + w3 * (w + 2) + w4 * (w + 3) <= W ) {
                        res = max(res, v1 + v2 + v3 + v4);

                    }
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}

