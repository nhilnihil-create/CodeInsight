#include<iostream>
#include<vector>
#include<bitset>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define arep(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    rep(i, 0, N) cin >> A[i] >> B[i];
    ll ans = 0;
    bitset<30> X(K);
    rep(i, 0, N) {
        bool is_ok = true;
        rep(j, 0, 30) {
            if (X[j] == 0 && ((A[i] >> j) & 1)) {
                is_ok = false;
                break;
            }
        }
        if (is_ok) ans += B[i];
    }
    rep(i, 0, 30) {
        if (X[i] == 0) continue;
        bitset<30> now_k(X);
        rep(j, 0, i) now_k[j] = 1;
        now_k[i] = 0;
        ll now_ans = 0;
        rep(j, 0, N) {
            bool is_ok = true;
            rep(k, 0, 30) {
                if (now_k[k] == 0 && ((A[j] >> k) & 1)) {
                    is_ok = false;
                    break;
                }
            }
            if (is_ok) now_ans += B[j];
        }
        ans = max(ans, now_ans);
    }
    cout << ans << endl;
    return 0;
}