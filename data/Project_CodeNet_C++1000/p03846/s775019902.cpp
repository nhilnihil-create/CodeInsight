#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i,N) for(int i = 0; i < N; ++i)
using namespace std;

int main(){
    int N,ans = 0;
    int MOD = 1e9 + 7;
    cin >> N;
    vector<int> A(N), B(N,0);
    rep(i, N) cin >> A[i];
    rep(i, N/2) B[i] = B[N-i-1] = N-2*i-1;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    bool flag = true;
    rep(i, N) if(A[i] != B[i]) flag = false;
    if(flag){
        ans = 1;
        rep(i, N/2) ans =  ans * 2 % MOD;
    } 
    cout << ans << endl;
}