#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)

int main() {
    ll A, B, C;
    cin >> A >> B >> C;

    ll ans = 0;
    ll A1 = A, B1 = B, C1 = C;
    ll A2, B2, C2;
    while(A1 % 2 == 0 && B1 % 2 == 0 && C1 % 2 == 0) {
        ++ans;
        A2 = (B1 + C1) / 2;
        B2 = (A1 + C1) / 2;
        C2 = (A1 + B1) / 2;
        A1 = A2, B1 = B2, C1 = C2;

        if(A1 == A && B1 == B && C1 == C) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;

    return 0;
}