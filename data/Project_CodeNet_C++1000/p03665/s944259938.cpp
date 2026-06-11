#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, P;
    cin >> N >> P;
    bool odd = false;
    REP(i, N) {
        int A;
        cin >> A;
        if (A % 2) odd = true;
    }

    ll ans;
    if (odd) ans = 1LL << (N-1);
    else if (P) ans = 0;
    else ans = 1LL << N;
    cout << ans << endl;
}