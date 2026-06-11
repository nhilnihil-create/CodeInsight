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
    vi T(N), A(N);
    rep(i, N) {
        cin >> T[i] >> A[i];
    }

    ll a = 1, t = 1;
    for (int i = 0; i < N; i++) {
        ll x = t / T[i];
        if (t % T[i] != 0) x++;

        ll y = a / A[i];
        if (a % A[i] != 0) y++;

        ll co = max(x, y);

        t = co * T[i];
        a = co * A[i];
    }

    cout << (a + t) << endl;
}