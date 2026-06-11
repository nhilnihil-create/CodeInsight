#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, P;
    cin >> N >> P;
    int m = 0;
    for (int i = 0; i < N; ++i) {
        int A; cin >> A;
        if (A % 2 == 1) ++m;
    }
    if (m == 0) cout << (P == 0 ? (1LL<<N) : 0) << endl;
    else cout << (1LL<<(N-1)) << endl;
}