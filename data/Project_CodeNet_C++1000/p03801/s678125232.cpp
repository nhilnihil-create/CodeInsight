#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n;
int A[100001];
pii P[100001];
llong ans[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        P[i] = min(P[i - 1], pii(-A[i], i));
    }
    priority_queue<pll> pq;
    for (int p = P[n].second, r = n; p > 0; p = P[p - 1].second) {
        while (p <= r) pq.emplace(A[r--], 1);
        int v = -P[p - 1].first;
        llong c = 0;
        while (!pq.empty() && v <= pq.top().first) {
            ans[p] += (pq.top().first - v) * pq.top().second;
            c += pq.top().second;
            pq.pop();
        }
        pq.emplace(v, c);
    }
    for (int i = 1; i <= n; ++i) printf("%lld\n", ans[i]);
    return 0;
}