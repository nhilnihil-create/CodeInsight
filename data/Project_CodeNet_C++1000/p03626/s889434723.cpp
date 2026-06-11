#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod=1e9+7;
ll dp[2][55];
ll n;
string s1,s2;

int main(){
    cin >> n;
    cin >> s1 >> s2;
    if(s1[0]==s2[0]){
        dp[0][0]=3;
        dp[1][0]=3;
        for(ll i=1;i<n;i++){
            if(s1[i]==s2[i]&&s1[i-1]==s2[i-1]){
                dp[0][i]=dp[0][i-1]*2%mod;
                dp[1][i]=dp[1][i-1]*2%mod;
            }
            else if(s1[i]!=s2[i]&&s1[i-1]==s2[i-1]){
                dp[0][i]=dp[0][i-1]*2%mod;
                dp[1][i]=dp[1][i-1]*2%mod;
                dp[0][i+1]=dp[0][i-1]*2%mod;
                dp[1][i+1]=dp[1][i-1]*2%mod;
                i++;
            }
            else if(s1[i]==s2[i]&&s1[i-1]!=s2[i-1]){
                dp[0][i]=dp[0][i-1];
                dp[1][i]=dp[1][i-1];
            }
            else if(s1[i]!=s2[i]&&s1[i-1]!=s2[i-1]){
                dp[0][i]=dp[0][i-1]*3%mod;
                dp[1][i]=dp[1][i-1]*3%mod;
                dp[0][i+1]=dp[0][i-1]*3%mod;
                dp[1][i+1]=dp[1][i-1]*3%mod;
                i++;
            }
        }
    }
    else{
        dp[0][0]=6;
        dp[0][1]=6;
        dp[1][0]=6;
        dp[1][1]=6;
        for(ll i=2;i<n;i++){
            if(s1[i]==s2[i]&&s1[i-1]==s2[i-1]){
                dp[0][i]=dp[0][i-1]*2%mod;
                dp[1][i]=dp[1][i-1]*2%mod;
            }
            else if(s1[i]!=s2[i]&&s1[i-1]==s2[i-1]){
                dp[0][i]=dp[0][i-1]*2%mod;
                dp[1][i]=dp[1][i-1]*2%mod;
                dp[0][i+1]=dp[0][i-1]*2%mod;
                dp[1][i+1]=dp[1][i-1]*2%mod;
                i++;
            }
            else if(s1[i]==s2[i]&&s1[i-1]!=s2[i-1]){
                dp[0][i]=dp[0][i-1];
                dp[1][i]=dp[1][i-1];
            }
            else if(s1[i]!=s2[i]&&s1[i-1]!=s2[i-1]){
                dp[0][i]=dp[0][i-1]*3%mod;
                dp[1][i]=dp[1][i-1]*3%mod;
                dp[0][i+1]=dp[0][i-1]*3%mod;
                dp[1][i+1]=dp[1][i-1]*3%mod;
                i++;
            }
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}  
