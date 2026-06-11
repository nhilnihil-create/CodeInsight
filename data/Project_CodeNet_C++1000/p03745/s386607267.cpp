#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) { cin >> A[i]; }

    int ans = 1;
    int mode = 3;

    for (int i = 1; i < N; i++) {
        if (mode == 1 && A[i] < A[i - 1]) {
            ans++;
            mode = 3;
        } else if (mode == 2 && A[i] > A[i - 1]) {
            ans++;
            mode = 3;
        } else if (mode == 3 && A[i] > A[i - 1]) {
            mode = 1;
        } else if (mode == 3 && A[i] < A[i - 1]) {
            mode = 2;
        }
    }
    cout << ans << endl;
}