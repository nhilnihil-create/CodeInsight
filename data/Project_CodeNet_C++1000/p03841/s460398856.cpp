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

    int N;
    cin >> N;
    vector<P> v(N + 1);
    v[0].F = INF;
    v[0].S = INF;
    int num[505];
    int pos[505];
    int res[250005] = {};
    for(int i = 1; i <= N; ++i) {
        cin >> v[i].F;
        v[i].S = i;
        pos[i] = v[i].F;
        num[i] = N - 1;
        res[v[i].F] = i;
    }
    sort(all(v));

    int np = 1;
    for(int i = 0; i < v.size() - 1; ++i) {
        for(int j = 1; j < v[i].S; ++j) {
            if(res[np] == v[i].S) {
                cout << "No" << endl;
                return 0;
            }
            if(res[np] != 0) {
                ++np;
                --j;
                continue;
            }
            num[v[i].S]--;

            res[np] = v[i].S;
            ++np;
        }
    }

    sort(all(v), greater<P>());
    np = N * N;
    for(int i = 1; i <= N; ++i) {
        while(num[v[i].S] > 0) {
            if(v[i].F == np) {
                cout << "No" << endl;
                return 0;
            }
            if(res[np] != 0) {
                --np;
                continue;
            }
            res[np] = v[i].S;
            --np;
            --num[v[i].S];
        }
    }

    cout << "Yes" << endl;
    for(int i = 1; i <= N * N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
