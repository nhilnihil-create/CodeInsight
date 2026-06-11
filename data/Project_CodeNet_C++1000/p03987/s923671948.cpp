#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef __int128 lll;
constexpr ll mod = 1000000007;

int main() {
    ll n, a[200000], r[200000][2];
    cin >> n;
    priority_queue<pair<ll, ll>> q;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++) {
        q.push(make_pair(a[i], i));
        while (q.top().first > a[i]) {
            r[q.top().second][0] = i;
            q.pop();
        }
    }
    while (!q.empty()) {
        r[q.top().second][0] = n;
        q.pop();
    }
    for (ll i = n - 1; i >= 0; i--) {
        q.push(make_pair(a[i], i));
        while (q.top().first > a[i]) {
            r[q.top().second][1] = i;
            q.pop();
        }
    }
    while (!q.empty()) {
        r[q.top().second][1] = -1;
        q.pop();
    }
    ll c = 0;
    for (ll i = 0; i < n; i++) {
        ll l2 = i - r[i][1];
        ll r2 = r[i][0] - i;
        c += l2 * r2 * a[i];
    }
    cout << c << endl;
}