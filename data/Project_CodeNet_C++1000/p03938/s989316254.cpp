#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

int main(void){
    int N; cin >> N;
    int p[N]; rep(i, N){int temp; cin >> temp; temp--; p[i] = temp;}
    int A[N], B[N];
    A[0] = N; B[0] = N*N;
    rep(i, N){
        if(i == 0) continue;
        A[i] = A[i-1] + N; B[i] = B[i-1] - N;; 
    }
    rep(i, N){
        B[p[i]] += i;
    }
    rep(i, N) cout << A[i] << " "; cout << endl;
    rep(i, N) cout << B[i] << " "; cout << endl;
    //int C[N]; rep(i, N) C[i] = A[p[i]] + B[p[i]];
    //rep(i, N) cout << C[i] << " "; cout << endl;

    return 0;
}