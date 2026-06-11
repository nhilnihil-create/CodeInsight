#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < n; ++i)
#define rrep(i, n) for (int i = n - 1; i > -1; --i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
const long long INF = 1000000000;
typedef long long ll;
typedef pair<int, int> P;

bool judge(vector<ll> h, ll a, ll b, ll cnt, ll n) {
    rep(i, 0, n) {
        h[i] -= b * cnt;
    }
    ll d = a - b;
    rep(i, 0, n) {
        if (h[i] < 0) return true;
        ll e = h[i] / d;
        if (h[i] % d != 0) e++;
        h[i] -= e * d;
        cnt -= e;
        if (cnt < 0) return false;
    }
    return true;
}

void func(long long N, long long A, long long B, std::vector<long long> h) {
    sort(rall(h));
    ll m_cnt = h[0] / B;
    ll ng = 0;
    ll ok = m_cnt + 1;

    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (judge(h, A, B, mid, N))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;
}

int main() {
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld", &N);
    long long A;
    scanf("%lld", &A);
    long long B;
    scanf("%lld", &B);
    std::vector<long long> h(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &h[i]);
    }
    func(N, A, B, std::move(h));
    return 0;
}
