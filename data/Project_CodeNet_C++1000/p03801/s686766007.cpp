#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define RREP(i, n) for (int i = n - 1; i < (int)n; --i)
#define FOR(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define RFOR(i, l, r) for (int i = (int)(r); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int N;
    cin >> N;
    priority_queue<pair<int, int>> pq;
    REP(i, N) {
        int a;
        cin >> a;
        pq.emplace(a, i);
    }

    vll ans(N, 0);
    ll a, i, cnt = 1; 
    tie(a, i) = pq.top(); pq.pop();
    while (!pq.empty()) {
        ll b, j;
        tie(b, j) = pq.top(); pq.pop();
        ans[i] += (a - b) * cnt++;
        a = b, i = min(i, j);
    }
    ans[i] += a * cnt;

    REP(i, N) cout << ans[i] << endl;
    
    return 0;
}