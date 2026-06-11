#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    int N;
    cin >> N;
    vl A(N);
    vl sum(N);
    rep(i, N) {
        cin >> A[i];
        sum[i] = A[i];
    }
    rep(i, N - 1) {
        sum[i + 1] += sum[i];
    }

    // +-+-+-....
    ll diff = 0;
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        ll x = sum[i] + diff;
        // +
        if (i % 2 == 0) {
            if (x < 0) {
                diff += abs(x) + 1;
                cnt += abs(x) + 1;
            } else if (x == 0) {
                diff += 1;
                cnt++;
            }
        }
        // -
        else {
            if (x > 0) {
                diff -= abs(x) + 1;
                cnt += abs(x) + 1;
            } else if (x == 0) {
                diff -= 1;
                cnt++;
            }
        }
    }

    // -+-+-+....
    ll diff2 = 0;
    ll cnt2 = 0;
    for (int i = 0; i < N; i++) {
        ll x = sum[i] + diff2;
        // +
        if (i % 2 == 1) {
            if (x < 0) {
                diff2 += abs(x) + 1;
                cnt2 += abs(x) + 1;
            } else if (x == 0) {
                diff2 += 1;
                cnt2++;
            }
        }
        // -
        else {
            if (x > 0) {
                diff2 -= abs(x) + 1;
                cnt2 += abs(x) + 1;
            } else if (x == 0) {
                diff2 -= 1;
                cnt2++;
            }
        }
    }

    cout << min(cnt, cnt2) << endl;
}