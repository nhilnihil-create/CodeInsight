#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N), B(N);
    ll minv = 0;
    for (auto &e : A) { cin >> e; minv += e; }
    for (int i = 1; i < N; i++) {
        ll sum = 0;
        for (int j = 0; j < N; j++) B[(j+1)%N] = min(A[(j+1)%N], A[j]), sum += B[(j+1)%N];
        A = B;
        minv = min(minv, sum + i * X);
    }
    cout << minv << endl;
    return (0);
}
