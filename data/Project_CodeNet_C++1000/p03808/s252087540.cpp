#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];
    long long sum = accumulate(A.begin(), A.end(), 0LL);
    if(sum % (N * (N + 1) / 2LL)) {
        cout << "NO" << endl;
        return 0;
    }
    long long k = sum / (N * (N + 1) / 2LL);

    vector<long long> d(N);
    for(int i=0; i<N; ++i) {
        d[i] = A[(i + 1) % N] - A[i] - k;
    }
    
    for(int i=0; i<N; ++i) {
        if(d[i]) {
            if(d[i] % N != 0 || d[i] > 0) {
                cout << "NO" << endl;
                return 0;
            } else {
                k += d[i] / N;
            }
        }
    }

    if(k == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}