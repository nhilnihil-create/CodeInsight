#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;


int main() {
    ll N, A, B;
    cin >> N >> A >> B;

    B = B - A;
    A = 0;

    ll ans = 0;
    if (B < 0) ans = 0;
    else if (B == 0) ans = 1;
    else {
        if (N==1) ans = 0;
        else if (N==2) ans = 1;
        else ans = B * (N - 2) + 1;
    }

    cout << ans << endl;

    return 0;
}