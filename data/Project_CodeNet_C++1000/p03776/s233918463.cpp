#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define lcm(a, b) (a)/__gcd((a),(b))*(b)
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1000000007;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector<int> Div(int n) {
    vector<int> ret;
    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.pb(i);

            if(i * i != n) ret.pb(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

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

LL Bin(LL n, LL k) {
    if(k < 0 || n < k) {
        return 0;

    }
    LL ret = 1;
    for(LL i = 1; i <= k; ++i) {
        ret *= n--;
        ret /= i;

    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    LL n, a, b;
    cin >> n >> a >> b;

    vector< LL > v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];

    }
    sort(all(v), greater<LL>());
    LL mn = LINF;
    LL sum = 0;
    for(int i = 0; i < a; ++i) {
        sum += v[i];
        mn = v[i];

    }

    long double avg = (double)sum / a;

    int pos = 0;
    while(v[pos] != mn) {
        ++pos;

    }

    int p = pos;
    int cnt = 0;
    while(p < n && v[p] == mn) {
        ++p; ++cnt;

    }

    if(mn != v[0]) {
        printf("%.10Lf\n%lld\n", avg, Bin(cnt, a - pos));
        return 0;

    }

    LL res = 0;
    for(int i = a; i <= b; ++i) {
        res += Bin(cnt, i - pos);

    }
    printf("%.10Lf\n%lld\n", avg, res);

    return 0;
}

