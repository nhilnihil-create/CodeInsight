#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 200005
using namespace std;

char s[MAXN];
int len;
int dp[MAXN];
int pos[MAXN][30];

void solve(){
    len = strlen(s);
    for (int i = 0;i < 26;++i){
        pos[len][i] = len;
    }
    dp[len] = 1;
    dp[len+1] = 0;

    for (int i = len-1;i >= 0;--i){
        for (int j = 0;j < 26;++j){
            pos[i][j] = pos[i+1][j];
        }
        pos[i][s[i]-'a'] = i;
        dp[i] = len+1;
        for (int j = 0;j < 26;++j){
            dp[i] = min(dp[i], dp[pos[i][j]+1]+1);
        }
    }

    int T = dp[0];
    int p = 0;
    while (T--){
        for (int i = 0;i < 26;++i){
            if (dp[p] == dp[pos[p][i]+1]+1) {
                printf("%c", 'a'+i);
                p = pos[p][i]+1;
                break;
            }
        }
    }
    printf("\n");
}

int main(){
    scanf("%s", s);
    solve();
    return 0;
}