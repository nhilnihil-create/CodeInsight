#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    ll N;
    cin >> N;
    vector<ll> a(3 * N);
    rep(i, 3 * N) cin >> a[i];
    vector<ll> pre(N + 1), suf(N + 1);
    priority_queue<ll, vector<ll>, greater<ll>> pq1;
    priority_queue<ll> pq2;

    ll pre_sum = 0;
    ll suf_sum = 0;

    rep(i, N) {
        pre_sum += a[i];
        pq1.push(a[i]);
    }
    pre[0] = pre_sum;
    for(int i = N; i < 2 * N; i++) {
        pre_sum += a[i];
        pq1.push(a[i]);
        pre_sum -= pq1.top();
        pq1.pop();
        pre[i - N + 1] = pre_sum;
    }

    for(int i = 3 * N - 1; i >= 2 * N; i--) {
        suf_sum += a[i];
        pq2.push(a[i]);
    }
    suf[N] = suf_sum;
    for(int i = 2 * N - 1; i >= N; i--) {
        suf_sum += a[i];
        pq2.push(a[i]);
        suf_sum -= pq2.top();
        pq2.pop();
        suf[i - N] = suf_sum;
    }
    ll res = -LINF;
    rep(i, N + 1) { res = max(res, pre[i] - suf[i]); }
    cout << res << endl;
    return 0;
}