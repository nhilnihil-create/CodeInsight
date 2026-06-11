#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<ll>;
using P = pair<ll,ll>;

ll inv=500000004;

ll dp[5010][5010];//dp(n,x);
int main(){
    int n;cin >>n;
    string s;cin >>s;
    dp[1][1]=2;dp[1][0]=1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j > 0)dp[i + 1][j - 1] += dp[i][j];
            dp[i + 1][j - 1] %= mod;
            dp[i + 1][j + 1] += dp[i][j] * 2 % mod;
            dp[i + 1][j + 1] %= mod;
        }
        dp[i+1][0]+=dp[i][0];
        dp[i+1][0]%=mod;
    }
   // for (int l = 0; l < 5; ++l) {
     //   for (int i = 0; i < 5; ++i) {
       //     cout <<dp[l][i]<<" ";
        //}
        //cout <<endl;
    //}
    for (int k = 0; k < s.size(); ++k) {
        dp[n][s.size()]*=inv;
        dp[n][s.size()]%=mod;
    }
    cout <<dp[n][s.size()]<< endl;
    return 0;
}