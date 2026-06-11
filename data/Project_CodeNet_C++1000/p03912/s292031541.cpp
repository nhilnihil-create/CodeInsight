#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    int N, M, X, ans = 0;
    cin >> N >> M;
    vector<int> n(100001, 0), even(M, 0), odd(M, 0);
    rep(i, N) {
        cin >> X;
        n[X]++;
    }
    rep(i, 100001) {
        even[i % M] += n[i] / 2 * 2;
        odd[i % M] += n[i] % 2;
    }
    rep(i, M / 2 + 1) {
        if (i == 0 || i + i == M) ans += (even[i] + odd[i]) / 2;
        else {
            int x = even[i] + odd[i];
            int y = even[M - i] + odd[M - i];
            if (x == y) ans += x;
            else if (x < y) {
                ans += x + min(even[M - i], y - x) / 2;
            } else {
                ans += y + min(even[i], x - y) / 2;
            }
        }
    }
    cout << ans << "\n";
}