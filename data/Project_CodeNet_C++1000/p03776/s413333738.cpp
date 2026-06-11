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
const ll inf=1e9+7;
const ll INF=1e18;

int main(){
    int n,a,b;cin>>n>>a>>b;
    vll v(n);rep(i,n)cin>>v[i];
    sort(all(v));reverse(all(v));
    bool only=true;int last=0;
    ll sum=v[0];
    rep2(i,1,a){
        sum+=v[i];
        if(v[i]!=v[i-1]){
            only=false;
            last=i;
        }
    }
    vvll dp(n+1,vll(n+1));//dp[i][j]=iCj
    rep(i,n+1)dp[i][0]=(ll)1;
    rep2(i,1,n+1)rep2(j,1,n+1)dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
    int res=(ll)0;ll ans=(ll)0;
    if(only){
        rep(i,n)if(v[i]==v[0])res++;
        rep2(i,a,min(b,res)+1)ans+=dp[res][i];
    }
    else{
        rep(i,n)if(v[i]==v[a-1])res++;
        ans=dp[res][a-last];
        //cout<<a-last<<" "<<res<<endl;
    }
    decp(10);
    double av=(double)sum/(double)a;
    cout<<av<<endl;
    cout<<ans<<endl;
}