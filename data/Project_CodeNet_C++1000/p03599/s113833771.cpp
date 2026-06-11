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

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    double mx = 0.0;
    int resa = 100 * a, resb = 0;

    for(int i = 0; i <= f; i += 100 * a) {
        for(int j = 0; i + j <= f; j += 100 * b) {
            if(i == 0 && j == 0) continue;
            for(int k = 0; k + i + j <= f; k += c) {
                for(int l = 0; l + k + i + j <= f; l += d) {
                    int wa = i + j;
                    double su = k + l;
                    double mxsu = double(wa) / 100.0 * e;
                    if(su > mxsu) continue;
                    if(mx < (100 * su) / (wa + su)) {
                        mx = (100 * su) / (wa + su);
                        resa = wa + su;
                        resb = su;
                    }
                }
            }
        }
    }
    cout << resa << " " << resb << endl;
    return 0;
}

