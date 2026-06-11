#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int dp[200001];
int nx[200001][26];
const int INF=1000100010;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    rep(i,26) nx[n][i]=n+1;
    rep(i,n+1) dp[i]=INF;
    dp[n]=1;dp[n+1]=0;
    for(int i=n-1;i>=0;--i){
        int mn=INF;
        rep(j,26){
            if(s[i]-'a'==j) nx[i][j]=i+1;
            else nx[i][j]=nx[i+1][j];
            mn=min(mn,dp[nx[i][j]]+1);
        }
        dp[i]=mn;
    }
    string ans;
    int cur=0;
    while(1){
        rep(i,26)if(dp[nx[cur][i]]+1==dp[cur]){
            ans+='a'+i;
            cur=nx[cur][i];
            break;
        }
        if(cur>=n+1)break;
    }
    cout<<ans<<endl;
    //rep(i,26) sort(nx[i].begin(),nx[i].end());
    return 0;
}