#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N, L, Q;
    cin >> N;
    vector<int> x(N);
    REP(i, N) cin >> x[i];
    cin >> L;
    cin >> Q;
    vector<int> a(Q), b(Q);
    REP(i, Q){
        cin >> a[i] >> b[i];
        --a[i], --b[i];
        if(a[i] > b[i]) swap(a[i], b[i]);
    }

    // dp[k][i]: ホテル i から 2^k 以内に到達可能な最も右のホテル番号
    vector<vector<int>> dp(20, vector<int>(N));
    // initialize
    REP(i, N){
        dp[0][i] = upper_bound(x.begin(), x.end(), x[i]+L)-x.begin() - 1;
    }

    REP(k, 19){
        REP(i, N){
            dp[k+1][i] = dp[k][dp[k][i]];
        }
    }

    REP(i, Q){
        int ans = 0; 
        for(int k = 19; k >= 0; --k){
            if(dp[k][a[i]] < b[i]){
                a[i] = dp[k][a[i]];
                ans += (1<<k);
            }
        }
        cout << ++ans << endl;
    }

    return 0;
}