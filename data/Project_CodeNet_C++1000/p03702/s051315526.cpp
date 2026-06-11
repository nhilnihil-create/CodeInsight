#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

bool isOK(ll key, vector<ll> h, ll A, ll B) {
    ll cnt = 0;
    rep(i, h.size()) {
        h[i] -= (key * B);
        if (h[i] <= 0)
            continue;
        cnt += h[i] / (A - B) + (h[i] % (A - B) == 0 ? 0 : 1);
    }

    if (cnt <= key)
        return true;
    else
        return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> h(N);
    rep(i, N) { cin >> h[i]; }

    int ok = pow(10, 9), ng = 0;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (isOK(mid, h, A, B))
            ok = mid;
        else
            ng = mid;
    }

    cout << ok << endl;
}
