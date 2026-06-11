#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    vector<ll> A(3);
    rep(i, 3) cin >> A[i];
    rep(i, 3) {
        if (A[i] % 2 == 0) {
            cout << "0\n";
            return 0;
        }
    }
    sort(A.begin(), A.end());
    cout << A[0] * A[1] << "\n";
}