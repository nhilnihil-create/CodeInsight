#include <bits/stdc++.h>
#define nmax 200005

using namespace std;

int fi[nmax][26];
int dp[nmax];

int main(){
    string s;
    cin >> s;
    int n=s.size();
    vector <int> h(26,n);
    for(int i=n-1;i>=0;i--){
        h[s[i]-'a']=i;
        for(int j=0;j<26;j++){
            fi[i][j]=h[j];
        }
    }
    dp[n]=0,dp[n+1]=-1;
    h.assign(26,n);
    for(int i=n-1;i>=0;i--){
        h[s[i]-'a']=i;
        int mx=-1;
        for(int j=0;j<26;j++){
            mx=max(mx,h[j]);
        }
        dp[i]=1+dp[mx+1];
    }
    int cnt=dp[0],la=-1;
    //cout << cnt+1 << endl;
    for(int i=0;i<=cnt;i++){
        int req=cnt-i;
        for(int j=0;j<26;j++){
            if(dp[fi[la+1][j]+1]<req){
                cout << (char)(j+'a');
                la=fi[la+1][j];
                break;
            }
        }
    }
    cout << endl;
    return 0;
}