#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, L;
    cin >> N >> L;
    vector<int64_t> a(N);
    for (int64_t& A : a) {
        cin >> A;
    }

    for (int64_t i = 0; i < N - 1; i++) {
        if (a[i] + a[i + 1] < L) {
            continue;
        }

        cout << "Possible" << endl;
        for (int64_t j = 0; j < i; j++) {
            cout << j + 1 << endl;
        }
        for (int64_t j = N - 2; j >= i; j--) {
            cout << j + 1 << endl;
        }
        return 0;
    }

    cout << "Impossible" << endl;
}