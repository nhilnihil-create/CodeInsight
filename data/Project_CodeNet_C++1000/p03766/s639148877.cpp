#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vii         vector<pair<int,int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define endl '\n'
#define int long long int
using namespace std;

const int mod = (int)1e9 + 7;
const int lim = (int)1e6 + 7;
int n;
int dp[lim] = {0};
bool vis[lim] = {0};
int tot[lim] = {0};
int solve(int pos){
    if(pos <= 0)return 1;
    tot[1] = n;
    dp[1] = n;
    for(int pos = 2; pos <= n; pos++){
        int& ans = dp[pos];
        ans = 0;
        ans += dp[pos-1];
        if(pos >= 3)ans += tot[pos -3];
        ans += (n - max(pos-1, 2LL) +1);
        ans %= mod;
        ans += (n-1)*(n - 1);
        ans %= mod;
        tot[pos] = tot[pos-1] + ans;
        tot[pos] %= mod;
    }
    /*
    debug(pos);
    if(vis[pos])return dp[pos];
    vis[pos] = true;
    int& ans = dp[pos];
    ans = 0;
    ans += solve(pos-1); //placing 1 here
    debug(ans);
    if(pos >= 3)ans += tot[pos-2-1];
    //we have not accounted val >= pos and val = pos-1;
    ans += (n - max(pos-1, 2LL) +1);
    ans %= mod;
    ans += (n-1)*(n - 1);
    ans %= mod;
       for(int val = 2; val <= n;val++){
       ans += solve(pos - val - 1);//placing val here and 1's in the next  
       ans += n-1;//after val value we place non-1 number 
       ans %= mod;
       }
    tot[pos] = tot[pos-1] + ans;
    debug(pos);
    debug(tot[pos]);
    tot[pos] %= mod;
    */
    return dp[n];
}
//111113111132222222222
//31111131111211121124444444
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n; 

    cout << solve(n);
}



