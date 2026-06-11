#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int mod = 1e9+7;
const int INF = 1e9;
const int MAX = 1e6;

int main() {
    int n;
    cin >> n;
    vi a(n);
    map<int, int> m;
    rep(i, n) {
        cin >> a[i];
        m[a[i]]++;
    }
    priority_queue<int> pq;
    for (auto x : m) {
        if (x.second >= 2) pq.push(x.first);
    }
    if (pq.size() <= 1) {
        cout << 0 << endl;
    } else {
        ll x = pq.top();
        pq.pop();
        ll y = pq.top();
        pq.pop();
        if (m[x] >= 4) cout << x * x << endl;
        else cout << x * y << endl;
    }
}