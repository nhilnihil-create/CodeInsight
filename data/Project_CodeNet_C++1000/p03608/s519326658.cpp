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
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i,s,n) for(ll i=(s);i<(ll)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

int main(){
    ll n,m,r;cin>>n>>m>>r;
    vll city(r);
    rep(i,r)cin>>city[i];
    vvll dp(n,vll(n,INF));
    rep(i,n)dp[i][i]=0;
    rep(i,m){
        ll a,b,c;cin>>a>>b>>c;
        dp[a-1][b-1]=c;
        dp[b-1][a-1]=c;
    }
    rep(k,n)rep(i,n)rep(j,n)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    ll sum=0;
    ll mi=INF;
    sort(all(city));
    do{
        sum=0;
        rep(i,r-1)sum+=(ll)dp[city[i]-1][city[i+1]-1];
        mi=min(mi,sum);
    }while(next_permutation(all(city)));
    cout<<mi<<endl;
}