#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 2e5 + 5;
int a[26];

char s[maxn];

int nxt[maxn][26];
int dp[maxn];
int n;

int main(){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    memset(a, -1, sizeof(a));
    for(int i = n;i >= 1;i--){
        for(int j = 0;j < 26;j++){
            nxt[i][j] = a[j];
        }
        a[s[i] - 'a'] = i;
    }
    for(int i = 0;i < 26;i++){
        nxt[0][i] = a[i];
    }
    for(int i = n;i >= 0;i--){
        dp[i] = 1e9;
        for(int j = 0;j < 26;j++){
            if(nxt[i][j] == -1){
                dp[i] = 1;
            }else{
                dp[i] = min(dp[i], dp[nxt[i][j]] + 1);
            }
        }
    }
    int len = dp[0];
    int now = 0;
    string ans = "";
    for(int i = 1;i < len;i++){
        for(int j = 0;j < 26;j++){
            if(dp[nxt[now][j]] == len - i){
                ans.push_back('a' + j);
                now = nxt[now][j];
                break;
            }
        }
    }
    for(int j = 0;j < 26;j++){
        if(nxt[now][j] == -1){
            ans.push_back('a' + j);
            break;
        }
    }
    cout << ans << endl;
    return 0;
}

