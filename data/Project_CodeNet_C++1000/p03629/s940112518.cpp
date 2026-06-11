#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=1e18;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    int next[n+2][26],tmp[26];
    fill(tmp,tmp+26,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            next[i+1][j]=tmp[j];
        }
        tmp[s[i]-'a']=i+1;
    }
    for(int i=0;i<26;i++){
        next[n+1][i]=tmp[i];
    }
    int dp[n+2];
    int par[n+2],c[n+2];
    fill(dp,dp+n+2,INF);
    dp[n+1]=0;
    for(int i=n+1;i>=1;i--){
        for(int j=0;j<26;j++){
            int to=next[i][j];
            if(dp[to]>dp[i]+1){
                dp[to]=dp[i]+1;
                par[to]=i;
                c[to]=j;
            }
            else if(dp[to]==dp[i]+1){
                if(to==0){
                    if(c[to]>j){
                        par[to]=i;
                        c[to]=j;
                    }
                    else if(c[to]==j&&c[par[to]]>c[i]){
                        par[to]=i;
                        c[to]=j;
                    }
                }
                if(c[par[to]]>c[i]){
                    par[to]=i;
                    c[to]=j;
                }
            }
        }
    }
    int now=0;
    while(now<n+1){
        cout<<char('a'+c[now]);
        now=par[now];
    }
    cout<<endl;
}
