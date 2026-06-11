#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;
int main(){
    long long N;
    cin >> N;
    vector<long long> T(N), A(N);
    for(int i = 0; i < N; i++) cin >> T[i];
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 1; i < N; i++){
        if(T[i] > T[i - 1] && T[i] > A[i]){
            cout << 0 << endl;
            return 0;
        }
        if(A[N - i] < A[N - 1 - i] && A[N - 1 - i] > T[N - 1 - i]){
            cout << 0 << endl;
            return 0;
        }
    }
    if(T[N - 1] != A[0]){
        cout << 0 << endl;
        return 0;
    }
    long long ans = 1;
    for(int i = 1; i <= N - 1 - i; i++){
        if(i == N - 1 - i) {
            if(T[i] == T[i - 1] && A[N - 1 - i] == A[N - i]) ans = ans*min(T[i], A[i]) % MOD;
        }
        else{
            if(T[i] == T[i - 1] && A[i] == A[i + 1])ans = ans * min(T[i], A[i]) % MOD;
            if(T[N - 1 - i] == T[N - 2 - i] && A[N - 1 - i] == A[N - i]) ans = ans * min(T[N - 1 - i], A[N - 1 - i]) % MOD;
        }
    }
    cout << ans << endl;
}