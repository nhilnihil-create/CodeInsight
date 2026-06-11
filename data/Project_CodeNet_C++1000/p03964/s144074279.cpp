#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> T(N), A(N);
    rep(i, N) cin >> T[i] >> A[i];

    ll t = T[0];
    ll a = A[0];
    for (int i = 1; i < N; i++) {
        if (t <= T[i] && a <= A[i]) {
            t = T[i];
            a = A[i];
            continue;
        }

        ll m1 = t / T[i];
        if (t % T[i]) m1++;

        ll m2 = a / A[i];
        if (a % A[i]) m2++;

        ll m = max(m1, m2);
        t = T[i] * m;
        a = A[i] * m;
    }

    cout << t + a << endl;
}