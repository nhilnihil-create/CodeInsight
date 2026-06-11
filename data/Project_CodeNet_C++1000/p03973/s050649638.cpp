#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<long long> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];
    
    long long mi = 1;
    long long res = 0;
    for(int i=0; i<N; ++i) {
        if(A[i] > mi) {
            res += (A[i] - 1) / mi;
            A[i] = 1;
        }
        mi = max(mi, A[i] + 1);
    }
    cout << res << endl;
}