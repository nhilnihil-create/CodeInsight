#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>
long MOD = 1000000007;

int main() {
    int N, M;
    cin>>N>>M;
    vl X(N), Y(M);
    REP(i, 0, N) cin >> X[i];
    REP(i, 0, M) cin >> Y[i];
    vector<long long> X_T(N), Y_T(M), X_Mer(N), Y_Mer(M);
    X_T[0] = N-1; X_T[N-2] = N-1;
    Y_T[0] = M-1; Y_T[M-2] = M-1;
    REP(i, 0, N-1) X_Mer[i] = X[i+1]- X[i];
    REP(i, 0, M-1) Y_Mer[i] = Y[i+1]- Y[i];
    REP(i, 1, (N+1)/2) X_T[i] = X_T[N - 2 - i] = (X_T[i-1] +  N - 1 - i * 2) % MOD; 
    REP(i, 1, (M+1)/2) Y_T[i] = Y_T[M - 2 - i] = (Y_T[i-1] + M - 1 - i * 2) % MOD; 

    long long X_sum = 0, Y_sum = 0;
    REP(i, 0, N-1){
        X_sum += X_Mer[i] * X_T[i] % MOD;
        X_sum %= MOD;
    }    
    REP(i, 0, M-1){
        Y_sum += Y_Mer[i] * Y_T[i] % MOD;
        Y_sum %= MOD;
    }
    long long ans = X_sum * Y_sum % MOD;
    cout << ans << endl;
    /*
    REP(i, 0, N-1) cout << X_T[i] << " ";
    cout << endl;
    REP(i, 0, M-1) cout << Y_T[i] << " ";
    cout << endl;
    */
}