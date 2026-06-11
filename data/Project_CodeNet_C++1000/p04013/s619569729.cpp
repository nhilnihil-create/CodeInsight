#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

int main(){
    int n,a;cin>>n>>a;
    vin x(n);
    rep(i,n){
        cin>>x[i];
        x[i]-=a;
    }
    vvll dp(55,vll(5050));
    rep(i,110)dp[0][i]=0;
    dp[0][2500]=1;
    rep(i,n)rep(j,5050){
        if(j-5000<=x[i]&&x[i]<=j)dp[i+1][j]=dp[i][j]+dp[i][j-x[i]];
        else dp[i+1][j]=dp[i][j];
    }
    cout<<dp[n][2500]-1<<endl;
}