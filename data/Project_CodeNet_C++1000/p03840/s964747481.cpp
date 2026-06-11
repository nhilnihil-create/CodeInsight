#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define LCM(a, b) (a) / __gcd((a), (b)) * (b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
#define ln '\n'

using namespace std;
using LL = long long;
using ldouble = long double;
using P = pair<int, int>;
using LP = pair<LL, LL>;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1e9 + 7;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector<LL> Div(LL n) {
    vector<LL> ret;
    for(LL i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.pb(i);
            if(i * i != n) ret.pb(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    LL a, b, c, d;
    for(int i = 1; i <= 7; ++i) {
        int tmp;
        if(i == 1) cin >> a;
        else if(i == 2) cin >> b;
        else if(i == 4) cin >> c;
        else if(i == 5) cin >> d;
        else cin >> tmp;
    }

    LL res = b;
    LL t = min({a, c, d});
    res += t * 3;
    a -= t;
    c -= t;
    d -= t;
    int tmp = a % 2 + c % 2 + d % 2;
    if(tmp >= 2 && t > 0) {
        a++;
        c++;
        d++;
        res -= 3;
    }
    cout << res + (a / 2 * 2) + (c / 2 * 2) + (d / 2 * 2) << endl;

    return 0;
}
