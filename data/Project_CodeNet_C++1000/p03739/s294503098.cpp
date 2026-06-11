#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__

int main() {
    int N;
    cin >> N;
    vl A(N);
    vl sum(N);
    rep(i, N) {
        cin >> A[i];
        sum[i] = A[i];
    }
    for (int i = 1; i < N; i++) {
        sum[i] += sum[i - 1];
    }

    // +-+-+-...のパターン
    ll div1 = 0;
    ll cnt1 = 0;
    for (int i = 0; i < N; i++) {
        ll x = sum[i] + div1;
        // +
        if (i % 2 == 0) {
            if (x <= 0) {
                div1 += (1 - x);
                cnt1 += (1 - x);
            }
        }
        // -
        else {
            if (x >= 0) {
                div1 -= (1 + x);
                cnt1 += (1 + x);
            }
        }
    }

    // -+-+-+...のパターン
    ll div2 = 0;
    ll cnt2 = 0;
    for (int i = 0; i < N; i++) {
        ll x = sum[i] + div2;
        // +
        if (i % 2 == 1) {
            if (x <= 0) {
                div2 += (1 - x);
                cnt2 += (1 - x);
            }
        }
        // -
        else {
            if (x >= 0) {
                div2 -= (1 + x);
                cnt2 += (1 + x);
            }
        }
    }

    cout << min(cnt1, cnt2) << endl;
}