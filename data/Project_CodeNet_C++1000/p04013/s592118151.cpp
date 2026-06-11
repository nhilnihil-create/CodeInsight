/*
平均がaになるため, 各カードx[i]に-=aすると和を0にするに帰着
dp[i][j]: i枚以下のカードを選んだ時に和がjになる組み合わせの総数
dp[i][j] = dp[i - 1][j] + dp[i - 1][j - x[i]]
ここで-=aしているため, x[i]は負の値も取りうるため, 
必然的にjも負の値を取りうる.
初期値はdp[0][0] = 1とすれば良い.
したがって, dp[MAXn][MAXv * 2]となるようにdpを設定し, 
dp[i][MAXv]が和が0になる組み合わせの総数とする.
したがって, dp[0][MAXv] = 1を初期値.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
static const int MAX = 50;
int main(){
    int n, a;
    sc(n) sc(a)
    int x[n + 1];
    for (int i = 1; i <= n; i++) sc(x[i])
    for (int i = 1; i <= n; i++) x[i] -= a;
    /*
    dp[i][MAX*MAX+k]にはi枚以上選択した時の和が
    kになる組み合わせの総数が格納
    */
    vector<vector<ll>> dp(MAX + 1, vector<ll>(MAX*MAX*2 + 1, 0));
    for (int i = 0; i <= n; i++){
        for (ll j = 0; j <= 2*MAX*MAX; j++){
            if (i == 0 && j == MAX*MAX) dp[i][j] = 1;
            else if (i > 0 && j - x[i] >= 0 && j - x[i] <= 2*MAX*MAX){
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - x[i]];
            }else if (i > 0) dp[i][j] = dp[i - 1][j];
        }
    }
    /*
    k == 0の時は0枚選択した時の和が0になる
    組み合わせの数を1としているため,答え-1する
    */
    cout << dp[n][MAX*MAX] - 1 << endl;
    return 0;
}