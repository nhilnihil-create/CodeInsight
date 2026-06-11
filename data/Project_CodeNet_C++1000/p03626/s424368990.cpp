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

LL dp[SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    string s, t;
    cin >> s >> t;
    vector<int> v;
    for(int i = 0; i < N; ++i) {
        if(s[i] != t[i]) {
            v.pb(1);
            ++i;
        } else {
            v.pb(0);
        }
    }

    if(v[0] == 0) dp[0] = 3;
    else dp[0] = 6;
    for(int i = 1; i < v.size(); ++i) {
        if(v[i - 1] == 0) {
            if(v[i] == 0) dp[i] = dp[i - 1] * 2 % MOD;
            else dp[i] = dp[i - 1] * 2 % MOD;
        } else {
            if(v[i] == 0) dp[i] = dp[i - 1];
            else dp[i] = dp[i - 1] * 3 % MOD;
        }
    }
    cout << dp[v.size() - 1] << endl;
    return 0;
}

