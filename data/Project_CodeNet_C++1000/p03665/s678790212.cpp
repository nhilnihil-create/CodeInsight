#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, P;
    cin >> N >> P;

    int a, ne = 0, no = 0;
    rep(i, N) {
        cin >> a;
        if (a%2==0) ne++;
        else no++;
    }

    ll ans;
    if (no == 0) {
        if (P==1) ans = 0;
        else {
            ans = 1;
            rep(i, ne) ans *= 2;
        }
    } else {
        ans = 1;
        rep(i, N-1) ans *= 2;
    }

    cout << ans << endl;

    return 0;
}