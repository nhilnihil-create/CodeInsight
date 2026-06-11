#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define vec vector<ll>
#define mat vector<vector<ll> >
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
signed main(){
    string s;cin>>s;
    ll n=s.size();
    vector<string>dp(26);
    rep(i,26){
        dp[i]=(char)('a'+i);
    }
    for(int i=n-1;i>=0;i--){
        string a=s;
        rep(j,26){
            if(dp[j].size()<a.size()){
                a=dp[j];
            }
        }
        dp[s[i]-'a']=s[i]+a;
    }
    string a=s;
    rep(i,26){
        if(dp[i].size()<a.size()){
            a=dp[i];
        }
    }
    cout<<a<<endl;
}