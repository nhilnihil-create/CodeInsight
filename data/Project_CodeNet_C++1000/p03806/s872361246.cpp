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

static const int INF = 1000005;
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

int dp[45][505][505];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, ma, mb;
    cin >> n >> ma >> mb;
    vector<pair<P, int>> v;

    for(int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v.pb(MP(MP(a, b), c));

    }

    vector<P> ans;
    int x, y;
    x = ma, y = mb;
    while(x <= 500 && y <= 500) {
        ans.pb(MP(x, y));
        x += ma;
        y += mb;

    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= 500; ++j) {
            for(int k = 0; k <= 500; ++k) {
                dp[i][j][k] = INF;

            }
        }
    }

    for(int i = 0; i < n; ++i) {
        dp[i][0][0] = 0;
        int a, b, c;
        a = v[i].F.F;
        b = v[i].F.S;
        c = v[i].S;
        for(int j = 1; j <= 500; ++j) {
            for(int k = 1; k <= 500; ++k) {
                if(i == 0) {
                    if(j == a && k == b) {
                        dp[i][j][k] = c;

                    }
                } else {
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                    if(a <= j && b <= k) {
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - a][k - b] + c);

                    }
                }
            }
        }
    }

    int res = INF;
    for(int i = 0; i < ans.size(); ++i) {
        res = min(res, dp[n - 1][ans[i].F][ans[i].S]);


    }

    if(res == INF) {
        cout << -1;

    } else {
        cout << res;

    }
    cout << endl;
    return 0;
}

