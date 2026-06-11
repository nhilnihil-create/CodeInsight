#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,T;
    cin >> N >> T;
    vector<int> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];

    vector<int> B(N, 0);
    int m = A[0];
    for(int i=1; i<N; ++i) {
        B[i] = A[i] - m;
        m = min(m, A[i]);
    }
    
    cout << count(B.begin(), B.end(), *max_element(B.begin(), B.end())) << endl;
    return 0;
}