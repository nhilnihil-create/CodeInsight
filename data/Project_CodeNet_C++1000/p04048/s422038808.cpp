#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N, X;
    cin >> N >> X;
    
    ll ans = N;
    ll Y = N-X;
    if (X < Y) swap(X, Y);
    while (true) {
        if (X % Y == 0) {
            ans += Y*((X-Y)/Y)*2+Y;
            break;
        }
        ans += Y*2*(X/Y);
        ll Z = X%Y;
        X = Y;
        Y = Z;
    }
    cout << ans << endl;
    return 0;
}