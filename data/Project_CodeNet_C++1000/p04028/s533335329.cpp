#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1000000007;

int modPow(int a, int p){
    if(p == 0) return 1;
    long long res = modPow(a, p/2);
    res = (res * res)%MOD;
    if(p%2) res = (res * a)%MOD;
    return res;
}

int main(){
    int N;
    while(cin >> N){
        string S; cin >> S;
        vector<int> dp(N+1, 0);
        dp[0] = 1;
        for(int i=0;i<N;i++){
            vector<int> next(N+1, 0);
            for(int j=0;j<=N;j++){
                if(j < N){
                    next[j+1] += 2 * dp[j];
                    next[j+1] %= MOD;
                }
                next[max(0, j-1)] += dp[j];
                next[max(0, j-1)] %= MOD;
            }
            dp = next;
        }
        long long res = dp[S.size()];
        res *= modPow(modPow(2, S.size()), MOD-2);
        res %= MOD;
        cout << res << endl;
    }
}