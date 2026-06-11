#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=3.141592653589793;

int main() {
    ll n,w;
    cin>>n>>w;
    vector<pair<ll,ll>> p;
    rep(i,n){
        ll w1,v;
        cin>>w1>>v;
        p.push_back(make_pair(v,w1));
    }
    ll num=p[0].second;
    //最初に何個選ぶか決め打ち
    sort(all(p));
    reverse(all(p));
    /*rep(i,n){
      cout<<p[i].first<<" "<<p[i].second<<endl;}*/
    ll ans=0;
    //ll num=p[0].second;
    for (int i=1;i<n+1;i++){
        if (w<num*i){
            break;
        }
        else{
            ll w1=w-num*i;
            if (w1>=3*i){
                ll ans1=0;
                rep(j,i){
                    ans1+=p[j].first;
                }
                ans=max(ans1,ans);
                //cout<<ans<<endl;
            }
            else{
                ll dp[n+1][i+1][w1+1];
                rep(j,n+1){
                    rep(l,i+1){
                    rep(k,w1+1){
                        dp[j][l][k]=0;
                    }
                }}
                for (int j=1;j<n+1;j++){
                    for (int l=1;l<i+1;l++){
                        if (l>j){
                            continue;
                        }
                        else{
                    for (int k=0;k<w1+1;k++){
                        if (k>=p[j-1].second-num){
                            dp[j][l][k]=max(dp[j-1][l][k],dp[j-1][l-1][k-p[j-1].second+num]+p[j-1].first);
                        }
                        else{
                            dp[j][l][k]=dp[j-1][l][k];
                        }
                    }}
                }}
              
                /*rep(i,n+1){
                  rep(j,w1+1){
                    cout<<dp[i][j]<<" ";
                  }
                  cout<<endl;}*/
                ans=max(ans,dp[n][i][w1]);
                }
        }
    }
    cout<<ans<<endl;

    return 0;
}