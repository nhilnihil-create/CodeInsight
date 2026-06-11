#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

void solve() {
    int N, T, A;
    cin >> N >> T;
    int min_A = 1000000001, max_diff = 0, ans = 0;
    rep(i,N) {
        cin >> A;
        min_A = min(min_A, A);
        if (A - min_A == max_diff) ans++;
        if (A - min_A > max_diff) {
            max_diff = A - min_A;
            ans = 1;
        }
    }
    cout << ans << endl;
    return;
}

int main() {
    solve();
}