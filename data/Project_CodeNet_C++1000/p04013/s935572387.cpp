#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <list>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip> // setprecisionを使用するのに必要 cout << fixed << setprecision(15) << p でpを小数点以下15桁表示
using namespace std;
#define REPD(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) REPD(i, 0, n)
typedef long long ll;
#define fin(ans) cout << (ans) << '\n'
/*

*/
int main()
{
    ll dp[55][5000];
    int N;
    int A;
    int x[55];
    cin >> N >> A;
    REP(i,N) cin >> x[i], x[i] -= A;
    int GETA = 2500;
    memset(dp,0,sizeof(dp));
    dp[0][GETA] = 1;
    for(int i=0; i < N; i++){
        for(int s=0; s+x[i] < 5000; s++){
            if(dp[i][s]==0) continue;
            //選ばない場合
            dp[i+1][s] += dp[i][s];
            //選ぶ場合
            dp[i + 1][s + x[i]] += dp[i][s];
        }
    }
    fin(dp[N][GETA]-1);
    return 0;
}