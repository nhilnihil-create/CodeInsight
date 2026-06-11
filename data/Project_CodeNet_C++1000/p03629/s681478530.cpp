#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=200005;
char s[max_n];
int n;
int dp[max_n];
int nex[max_n][26];
char ans[max_n];
int main(){
    scanf(" %s",s+1);
    int n=strlen(s+1);
    for(int j=0;j<26;j++){
        nex[n+1][j]=n+1;
        for(int i=n;i>=1;i--){
            if(s[i]-'a'==j)nex[i][j]=i;
            else nex[i][j]=nex[i+1][j];
        }
    }
    dp[n+1]=1;
    for(int i=n;i>=1;i--){
        int mx=0;
        for(int j=0;j<26;j++)mx=max(mx,nex[i][j]);
        if(mx==n+1)dp[i]=1;
        else dp[i]=1+dp[mx+1];
    }
    int now=1;
    for(int i=1;i<=dp[1];i++){
        for(int j=0;j<26;j++){
            int nx=nex[now][j];
            if(i+dp[nx+1]==dp[1]){
                ans[i]=j+'a';
                now=nx+1;
                break;
            }
        }
    }
    ans[dp[1]+1]=0;
    printf("%s\n",ans+1);
    return 0;
}