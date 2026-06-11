#include <bits/stdc++.h>
using namespace std;

uint64_t ceil(uint64_t a, uint64_t b) {
    return a/b + (a % b == 0 ? 0 : 1);
}

int main() {
    uint64_t N, T, A, t_num = 1, a_num = 1, n;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> T >> A;
        n = max(ceil(t_num, T), ceil(a_num, A));
        t_num = T * n;
        a_num = A * n;
    }
    cout << t_num + a_num << endl;
    return 0;
}
