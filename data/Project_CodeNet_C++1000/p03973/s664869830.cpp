#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int N, A, P = 2;
    cin >> N >> A;
    ll ans = A - 1;
    rep(i, N - 1) {
        cin >> A;
        if (A < P) continue;
        if (A == P) {
            P++;
            continue;
        }
        ans += (A - 1) / P;
    }
    cout << ans << endl;
}