#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n + 1); i++)
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<bool> B(N);
    rep(i, N) { cin >> A[i]; }
    int ans = 0;
    int cnt = 1;
    bool P = false;
    rep(i, N) {
        B[cnt - 1] = true;
        cnt = A[cnt - 1];
        ans++;
        if (cnt == 2) {
            cout << ans << endl;
            P = true;
            break;
        } else if (B[cnt - 1] == true) {
            break;
            P = false;
        }
    }
    if (P == false) {
        cout << -1 << endl;
    }
}
