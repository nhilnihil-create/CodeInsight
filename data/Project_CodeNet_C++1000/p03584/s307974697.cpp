#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;
    vector<long long> A(N), B(N);
    for(int i=0; i<N; ++i) cin >> A[i] >> B[i];

    long long res = 0;
    for(int k=-1; k<30; ++k) {
        if(k == -1 || ((K >> k) & 1)) {
            long long mask = 0;
            for(int i=0; i<k; ++i) {
                mask |= (1LL << i);
            }
            for(int i=k+1; i<30; ++i) {
                mask |= (K & (1LL << i));
            }

            long long tmp = 0;
            for(int i=0; i<N; ++i) {
                if((mask | A[i]) == mask) tmp += B[i];
            }
            res = max(res, tmp);
        }
    }
    cout << res << endl;
}