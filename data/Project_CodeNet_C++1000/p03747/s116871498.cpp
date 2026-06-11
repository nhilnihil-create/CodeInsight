#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main() {
    Int N, L, T; cin >> N >> L >> T; L *= 2, T *= 2;
    vector<int> X(N), W(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> W[i], X[i] *= 2;
    Int idx = 0;
    for (int w : W) if (w == 2) idx += N - 2;
    idx = idx * (T / L) % N;
    T %= L;
    queue<int> Q1, Q2;
    for (int i = (idx + N - 1) % N; i != idx; (i += N - 1) %= N) {
        if (W[i] == 1) Q1.push(i);
    }
    for (int i = (idx + 1) % N; i != idx; (i += 1) %= N) {
        if (W[i] == 2) Q2.push(i);
    }
    if (W[idx] == 1) swap(Q1, Q2);
    int t = 0;
    while (!Q1.empty()) {
        int idy = Q1.front();
        Q1.pop();
        Int a = X[idx] + t * (W[idx] == 1 ? +1 : -1);
        a = ((a % L) + N) % L;
        Int b = X[idy] + t * (W[idy] == 1 ? +1 : -1);
        b = ((b % L) + N) % L;
        if (W[idx] == 1 && !(a < b)) b += L;
        if (W[idx] == 2 && !(b < a)) a += L;
        t += abs(a - b) / 2;
        if (t >= T) break;
        idx = idy;
        swap(Q1, Q2);
    }
    vector<tuple<Int, int, int>> A;
    for (int i = 0; i < N; i++) {
        Int a = X[i] + T * (W[i] == 1 ? +1 : -1);
        a %= L;
        if (a < 0) a += L;
        A.emplace_back(a, W[i], i);
    }
    sort(begin(A), end(A));
    for (int i = 0; i < N; i++) {
        if (get<2>(A[i]) == idx) {
            idx = i;
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << get<0>(A[(idx + i) % N]) / 2 << '\n';
    }
    return 0;
}
