#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXA 1001
#define MAXB 1001
#define MAXH 1000000001
#define MAXW 405
#define INF 5000
#define MAXN 41
#define MAXM 1001
#define MAXP 1000001
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;

int N, Ma, Mb;
int dp[MAXW][MAXW], a[MAXN], b[MAXN], c[MAXN];


int main(){
    cin >> N >> Ma >> Mb;
    for(int i = 0;i < N;i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    for(int i = 0;i < MAXW;i++){
        fill(dp[i], dp[i] + MAXW, INF);
    }


    dp[0][0] = 0;
    for(int i = 0;i < N;i++){
        for(int j = MAXW - 1;j >= 0;j--){
            for(int k = MAXW - 1;k >= 0;k--){
                if(j - a[i] >= 0 && k - b[i] >= 0)dp[j][k] = min(dp[j][k], dp[j - a[i]][k - b[i]] + c[i]);
            }
        }
    }


    int ans = INF;
    for(int i = 1;i * Ma < MAXW && i * Mb < MAXW;i++){
        ans = min(dp[i * Ma][i * Mb], ans);
    }

    if(ans == INF) printf("-1\n");
    else printf("%d\n", ans);

    return 0;
}