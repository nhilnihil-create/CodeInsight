#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

int n, Ma, Mb;
int a[50], b[50], c[50];
// dp[i][j][k] := i番目までの薬局をみて, タイプAの薬がjグラムで, Bの薬がkグラムの時の最小費用  
int dp[50][500][500];
const int INF = 1 << 30;

int main(void){
    cin >> n >> Ma >> Mb;
    rep(i, n) cin >> a[i] >> b[i] >> c[i];
    rep(i, 50)rep(j, 500)rep(k, 500)dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    rep(i, n){
        rep(j, 500)rep(k, 500){
            if(dp[i][j][k] == INF) continue;
            //i番目の薬局を使う
            chmin(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
            //i番目の薬局を使わない
            chmin(dp[i + 1][j][k], dp[i][j][k]);
        }
    }

    int ans = INF;
    for(int i = 1; i < 50; i++){
        int A = Ma * i, B = Mb * i;
        if(A > 490 || B > 490) break;
        chmin(ans, dp[n][A][B]);
    }
    if(ans == INF) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}