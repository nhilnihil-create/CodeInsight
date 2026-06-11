#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#define REP(i,n) for ( int i=0; i<int(n); i++ )
using namespace std;

const int N=1e5+5;

int main() {
    int n,p;
    cin >> n >> p;
    vector<long long> dp(2);
    dp[0]=1;
    REP(i,n) {
        int a;
        cin >> a;
        vector<long long> ndp=dp;
        REP(j,2) {
            ndp[(j+a)%2]+=dp[j];
        }
        dp=ndp;
    }
    cout << dp[p] << '\n';
    return 0;
}


