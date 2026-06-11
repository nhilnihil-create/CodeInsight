#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}

int main() {
    int n;
    cin >> n;
    vl a(3 * n);
    for (int i = 0; i < 3 * n; ++i) {
        cin >> a[i];
    }
    priority_queue<ll, vl, greater<ll>> pq1;
    priority_queue<ll> pq2;
    deque<ll> frontSum;
    deque<ll> backSum;
    frontSum.push_back(0);
    backSum.push_back(0);
    for (int i = 0; i < n; ++i) {
        pq1.push(a[i]);
        frontSum.front() += a[i];
    }
    for (int i = 3 * n - 1; i >= 2 * n; --i) {
        pq2.push(a[i]);
        backSum.front() += a[i];
    }
    for (int i = n; i < 2 * n; ++i) {
        ll currSum = frontSum.back();
        pq1.push(a[i]);
        ll mini = pq1.top();
        pq1.pop();
        frontSum.push_back(currSum + a[i] - mini);
    }
    for (int i = 2 * n - 1; i >= n; --i) {
        ll currSum = backSum.front();
        pq2.push(a[i]);
        ll maxi = pq2.top();
        pq2.pop();
        backSum.push_front(currSum + a[i] - maxi);
    }
    ll ret = -INF;
    for (int i = 0; i <= n; ++i) {
        chmax(ret, frontSum[i] - backSum[i]);
    }
    cout << ret << "\n";

    return 0;
}