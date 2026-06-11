#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_ll.hpp>
//typedef boost::multiprecision::cpp_ll ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E18;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define endl "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);



int main(){fastio
    ll n,a,b;cin>>n>>a>>b;
    ll v[n+1];rep(i,1,n)cin>>v[i];
    l_l dp[n+1][n+1];
    rep(i,0,n)rep(j,0,n)dp[i][j]=l_l(-1,0);
    dp[0][0]=l_l(0,1);
    rep(i,1,n){
        rep(j,0,n){
            if(j==0){
                dp[i][j]=l_l(0,1);
            }else{
                if(dp[i-1][j].first==-1){
                    if(dp[i-1][j-1].first==-1){
                        dp[i][j]=l_l(-1,0);
                    }else{
                        dp[i][j]=l_l(dp[i-1][j-1].first+v[i],dp[i-1][j-1].second);
                    }
                }else{
                    if(dp[i-1][j-1].first==-1){
                        dp[i][j]=l_l(dp[i-1][j].first,dp[i-1][j].second);
                    }else{
                        if(dp[i-1][j].first==dp[i-1][j-1].first+v[i]){
                            dp[i][j]=l_l(dp[i-1][j].first,dp[i-1][j].second+dp[i-1][j-1].second);
                        }else if(dp[i-1][j].first>dp[i-1][j-1].first+v[i]){
                            dp[i][j]=l_l(dp[i-1][j].first,dp[i-1][j].second);
                        }else{
                            dp[i][j]=l_l(dp[i-1][j-1].first+v[i],dp[i-1][j-1].second);
                        }
                    }
                }
            }
        }
    }
    dd maxi=0;
    vector<ll> flag;
    rep(i,a,b){
        dd hoge=(dd)dp[n][i].first/(dd)i;
        if(fabs(maxi-hoge)<EPS){
            flag.pb(i);
        }else if(maxi<hoge){
            flag.clear();
            flag.pb(i);
            maxi=hoge;
        }
    }
    ll sum=0;
    rep(i,0,flag.size()-1){
        sum+=dp[n][flag[i]].second;
    }
    cout<<setprecision(20)<<maxi<<endl;
    cout<<sum<<endl;
    return 0;
}



