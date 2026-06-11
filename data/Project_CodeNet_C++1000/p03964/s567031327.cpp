#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<int> T(N), A(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i] >> A[i];
    }
    long long t = 1, a = 1;
    for (int i = 0; i < N; i++) {
        long long x = max((t + T[i] - 1) / T[i], (a + A[i] - 1) / A[i]);
        t = x * T[i];
        a = x * A[i];
    }
    cout << t + a << endl;
    return 0;
}