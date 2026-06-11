#include <bits/stdc++.h>
using namespace std;

long long N, A, B;
vector<long long> h;

bool check(long long m) {
    long long k = 0;
    for (int i = 0; i < N; i++) {
        long long H = h[i] - B * m;
        if (H <= 0) continue;
        k += (H + A - 1) / A;
    }
    return (k <= m);
}

int binary_search() {
    long long m, l = 0, r = 2e9;

    while (r - l > 0) {
        m = (r + l) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return r;
}

int main() {
    cin >> N >> A >> B;
    A -= B;
    h.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    cout << binary_search() << endl;
}
