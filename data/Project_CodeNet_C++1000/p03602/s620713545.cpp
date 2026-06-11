#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    long long res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i >= j) continue;

            bool flag = true;
            for (int k = 0; k < N; k++) {
                if (i == k || j == k) continue;

                if (A[i][k] + A[k][j] < A[i][j]) {
                    cout << -1 << endl;
                    return 0;
                }

                if (A[i][k] + A[k][j] == A[i][j]) flag = false;
            }

            if (flag) res += A[i][j];
        }
    }

    cout << res << endl;
    return 0;
}