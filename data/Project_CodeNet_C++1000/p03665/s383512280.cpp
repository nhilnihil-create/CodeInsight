#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,P;
    cin >> N >> P;
    vector<int>A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(A[i]%2 == 1) {
            cout << (long long)pow(2LL,N-1) << endl;
            return 0;
        }
    }
    if(P == 1) {
        cout << 0 << endl;
    }
    else{
        cout << (long long)pow(2LL,N) << endl;
    }
}