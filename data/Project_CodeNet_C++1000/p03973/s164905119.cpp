#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    long long ans = A[0] - 1;
    int p = 2;
    for (int i = 1; i < N; i++) {
        if (A[i] <= p) {
            if (A[i] == p) p++;
            else continue;
        } else {
            if (A[i] % p == 0) ans += A[i] / p - 1;
            else ans += A[i] / p;
        }
    }
    
    cout << ans << endl;
}
