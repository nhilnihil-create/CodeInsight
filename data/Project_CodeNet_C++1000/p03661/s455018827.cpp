#include<bits/stdc++.h>
#define F first
#define S second
#define endl '\n'
#define lcm( a, b ) ((a)/__gcd(a,b)*(b))
#define MP make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
typedef pair<int, P> iP;
typedef pair< LL, LL > LP;

const int INF = INT_MAX;
const int MIN = INT_MIN;
const LL LINF = LLONG_MAX;
const int MOD = 1000000000 + 7;
const int SIZE = 300005;

vector< int > Div( int n ) {
    vector< int > ret;
    for( int i = 1; i * i <= n; ++i ) {
        if( n % i ) {
            ret.pb( i );
            if( i * i != n ) ret.pb( n / i );

        }
    }
    sort( all( ret ) );
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    LL a[SIZE];
    LL d = 0;
    for( int i = 0; i < n; ++i ) {
        cin >> a[i];
        d += a[i];

    }

    LL sum = 0;
    LL res = LINF;
    for( int i = 0; i < n - 1; ++i ) {
        sum += a[i];
        d -= a[i];
        res = min( res, llabs( sum - d ) );

    }
    cout << res << endl;
    return 0;
}

