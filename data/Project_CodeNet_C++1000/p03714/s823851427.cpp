#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

typedef pair<ll, int> p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<ll> a(3 * N);

    for(int i = 0; i < 3 * N; i++) cin >> a[i];

    priority_queue<ll, vector<ll>, greater<ll> > lq;
    vector<ll> ls(N * 2);
    vector<ll> la(N + 1);

    ll lc = 0;

    ls[0] = a[0];
    for(int i = 1; i < 2 * N; i++) {
        ls[i] += ls[i - 1] + a[i];
    }

    for(int i = 0; i < N; i++) {
        lq.push(a[i]);
    }

    la[0] = ls[N - 1];
    for(int i = 0; i < N; i++) {
        lq.push(a[i + N]);
        lc += lq.top();
        lq.pop();
        la[i + 1] = ls[N + i] - lc;
    }

    priority_queue<ll> rq;
    vector<ll> rs(N * 2);
    vector<ll> ra(N + 1);

    ll rc = 0;

    rs[0] = a[3 * N - 1];
    for(int i = 1; i < 2 * N; i++) {
        rs[i] += rs[i - 1] + a[3 * N - 1 - i];
    }

    for(int i = 3 * N - 1; i >= 2 * N; i--) {
        rq.push(a[i]);
    }

    ra[0] = rs[N - 1];
    for(int i = 0; i < N; i++) {
        rq.push(a[2 * N - 1 - i]);
        rc += rq.top();
        rq.pop();
        ra[i + 1] = rs[N + i] - rc;
    }

    ll ans = -pow(10, 18);

    for(int i = 0; i <= N; i++) {
        ans = max(ans, la[i] - ra[N - i]);
    }

    cout << ans << endl;
}