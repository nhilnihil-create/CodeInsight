#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    ll N, X;
    cin >> N >> X;
    vl A(N);
    rep(i, N) { cin >> A[i]; }

    vl suma(N - 1);
    rep(i, N - 1) { suma[i] = A[i] + A[i + 1]; }

    ll cnt = 0;
    rep(i, N - 1) {
        if (suma[i] > X) {
            ll diff = suma[i] - X;
            A[i + 1] = min(diff, A[i + 1]);
            suma[i + 1] -= min(diff, A[i + 1]);
            cnt += diff;
        }
    }

    cout << cnt << endl;
}