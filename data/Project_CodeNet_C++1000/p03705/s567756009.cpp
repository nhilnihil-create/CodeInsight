#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long N, long long A, long long B) {
    if (B < A) {
        cout << 0 << endl;
        return;
    }
    if (N == 1) {
        if (A != B) {
            cout << 0 << endl;
            return;
        } else {
            cout << 1 << endl;
            return;
        }
    }
    ll min = (N - 1) * A + B;
    ll max = (N - 1) * B + A;
    cout << (max - min) + 1 << endl;
    return;
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long A;
    scanf("%lld", &A);
    long long B;
    scanf("%lld", &B);
    solve(N, A, B);
    return 0;
}
