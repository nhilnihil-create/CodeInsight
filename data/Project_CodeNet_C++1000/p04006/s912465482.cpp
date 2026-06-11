#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N), B(N);

    for (auto &e : A) cin >> e;

    ll minv = accumulate(begin(A), end(A), 0ll);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) B[(j+1)%N] = min(A[(j+1)%N], A[j]);
        A = B;
        minv = min(minv, accumulate(begin(A), end(A), 0ll) + i * X);
    }
    cout << minv << endl;
    return (0);
}