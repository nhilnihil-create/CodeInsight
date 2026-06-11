#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
int nxt[MAXN][30];
int dp[MAXN];
int main(){
    string s;
    cin>>s;
    int n = s.length();
    s='#'+s;
    for(int i=0;i<26;i++){
        nxt[n+1][i] = n+2;
    }
    for(int i=n;i>=0;i--){
        for(int j=0;j<26;j++){
            nxt[i][j] = nxt[i+1][j];
        }
        if(i){
            nxt[i][s[i]-'a'] = i;
        }
    }
   
    dp[n+1] = 1;
    for(int i=n;i>=0;i--){
        dp[i] = MAXN;
        for(int j=0;j<26;j++){
            dp[i] = min(dp[i],dp[nxt[i][j]+1]+1);
        }
    }
    
    int ind = 0;
   
    while(true){
        for(int i=0;i<26;i++){
            //cout<<i<<" "<<nxt[ind][i]+1<<endl;
            if(dp[ind] == dp[nxt[ind][i]+1]+1){
                cout<<(char)('a'+i);
                ind = nxt[ind][i]+1;
                break;
            }
        }
        if(ind>n){
            break;
        }
    }
}
