#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)

const int MAX = 1e5+10;

int N, M;
map<int, int> num_count[MAX];

ll sub1(int n) { // modで同じ数字同士でペアになる
    map<int, int> nums = num_count[n];
    ll sm = 0;
    for (auto iter = nums.begin(); iter != nums.end(); iter++) {
        sm += iter->second;
    }
    return sm / 2;
}

ll sub2(int n) {
    map<int, int> x = num_count[n], y = num_count[M-n];
    ll x_sum = 0, y_sum = 0;
    for (auto iter = x.begin(); iter != x.end(); iter++) x_sum += iter->second;
    for (auto iter = y.begin(); iter != y.end(); iter++) y_sum += iter->second;
    ll ret = min(x_sum, y_sum);
    if (x_sum < y_sum) {
        swap(x_sum, y_sum);
        swap(x, y);
    }
    ll count_pair = 0;
    for (auto iter = x.begin(); iter != x.end(); iter++) {
        count_pair += iter->second / 2;
    }
    return ret + min((x_sum - ret) / 2, count_pair);
}

ll solve() {
    ll ans = sub1(0);
    if (M%2 == 0) ans += sub1(M/2);
    FOR (i, 1, (M+1)/2) ans += sub2(i);
    return ans;
}

int main() {
    cin >> N >> M;
    REP (i, N) {
        int x;
        cin >> x;
        num_count[x%M][x]++;
    }
    cout << solve() << endl;
}