#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<cmath>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

ll dp[55][55][3000];

int main()
{
    int N,A; 
    cin >> N >> A;
    int x[N];
    for (int i=0; i<N; ++i) cin >> x[i];

    // ll dp[55][55][2500];// 一定数を超えるとエラー？main()外ならば定義可能．
    for (int i=0; i<55; ++i)
    {
        for (int j=0; j<55; ++j)
        {
            for (int k=0; k<3000; ++k)
            {
                dp[i][j][k] = 0;
            }
        }
    }

    dp[0][0][0] = 1;
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
        {
            for (int k=0; k<2500; ++k)
            {
                // if(dp[i][j][k] == 0) continue;
                dp[i+1][j][k] += dp[i][j][k];
                dp[i+1][j+1][k + x[i]] += dp[i][j][k];
                // cout << "i j k :" << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
            }
        }
    }

    long long res = 0;
    for (int j = 1; j <= N; ++j) {
        res += dp[N][j][A*j];
    }
    cout << res << endl;
    return 0;
}

// long long dp[55][55][2550];
// int N, A;
// int x[55];
 
// int main() {
//     cin >> N >> A;
//     for (int i = 0; i < N; ++i) cin >> x[i];
//     // memset(dp, 0, sizeof(dp));
//     dp[0][0][0] = 1;
    
//     for (int i = 0; i < N; ++i) {
//         for (int j = 0; j <= N; ++j) {
//             for (int k = 0; k <= 2550; ++k) {
//                 dp[i+1][j][k] += dp[i][j][k];
//                 dp[i+1][j+1][k + x[i]] += dp[i][j][k];
//             }
//         }
//     }
//     long long res = 0;
//     for (int j = 1; j <= N; ++j) {
//         res += dp[N][j][A*j];
//     }
//     cout << res << endl;
//     return 0;
// }