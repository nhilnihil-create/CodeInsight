#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i=0; i<N; ++i) {
        cin >> A[i];
        if(i > 0) A[i] += A[i-1];
    }

    long long res = 1001001001001001;
    for(int i=0; i+1<N; ++i) {
        res = min(res, abs(A[N-1] - A[i] - A[i]));
    }
    cout << res << endl;
}