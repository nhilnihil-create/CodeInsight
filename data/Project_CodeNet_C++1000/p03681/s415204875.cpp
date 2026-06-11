#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep2l(i, s, n) for (ll i = (ll)(s); i < (ll)n; i++)

ll kaijo(int start, int end, ll &ans) {
    rep2(i, start, end+1) {
        ans *= i;
        ans %= 1000000007;
    }
    return ans;
}

int main() {
    int N, M;
    cin >> N >> M;
    if (N >= M+2 || M >= N+2) {
        cout << 0 << endl;
        return 0;
    }
    if (abs(N-M) == 1) {
         ll resn = 1;
         ll resm = 1;
         cout << (kaijo(1, N, resn))*(kaijo(1, M, resm))%1000000007 << endl;
         return 0;
    }
    if (N==M) {
        ll resn = 1;
        ll resm = 1;
        cout << (2*kaijo(1, N, resn))*(kaijo(1, M, resm))%1000000007 << endl;
        return 0;
    }
}
