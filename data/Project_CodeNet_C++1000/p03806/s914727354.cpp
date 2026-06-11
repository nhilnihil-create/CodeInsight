#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG
#define fi first
#define se second

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

const double pi=acos(-1);
const ll MOD=1e9+7;
const ll INF=(1LL<<60);

int main() {
    int n,ma,mb;
    cin>>n>>ma>>mb;
    vector<pair<pair<int,int>,int>> vec;
    rep(i,n){
        int a,b,c;
        cin>>a>>b>>c;
        vec.push_back({{a,b},c});
    }
    vvvi dp(n+1,vvi(401,vi(401,5000)));
    rep(i,n+1)dp[i][0][0]=0;
    for (int i=1;i<n+1;i++){
        for (int j=1;j<401;j++){
            for (int k=1;k<401;k++){
                int a=vec[i-1].fi.fi;
                int b=vec[i-1].fi.se;
                if (j>=a && k>=b){
                    dp[i][j][k]=min(dp[i-1][j][k],dp[i-1][j-a][k-b]+vec[i-1].se);
                }
                else dp[i][j][k]=dp[i-1][j][k];
            }
        }
    }
    int ans=10000;
    for (int j=1;j<401;j++){
        for (int k=1;k<401;k++){
            if (j*mb!=k*ma)continue;
            else if (dp[n][j][k]==5000)continue;
            else ans=min(dp[n][j][k],ans);
        }
    }
    if (ans==10000)cout<<-1<<endl;
    else cout<<ans<<endl;


    return 0;
}