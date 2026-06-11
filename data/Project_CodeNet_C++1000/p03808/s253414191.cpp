#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long sum = accumulate(A.begin(), A.end(), 0LL);
    long long m = N * (N + 1) / 2;
    if (sum % m != 0) {
        cout << "NO" << endl;
        return 0;
    }
    long long num = sum / m;

    for (int i = 0; i < N; i++) {
        long long gap = 0;
        if (i != N - 1) {
            gap = A[i + 1] - A[i] - num;
        } else {
            gap = A[0] - A[N - 1] - num;
        }
        if (gap % N != 0 || gap > 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}