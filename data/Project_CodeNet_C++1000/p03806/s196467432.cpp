#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n;cin>>n;
    ll ma,mb;
    cin>>ma>>mb;
    vector<vector<vector<ll> > >dp(n+1,vector<vector<ll> >(411,vector<ll>(411,inf)));
    vector<ll>a(n),b(n),c(n);
    dp[0][0][0]=0;
    rep(i,n){
        cin>>a[i]>>b[i]>>c[i];
    }
    rep(i,n){
        rep(j,401){
            rep(k,401){
                if(dp[i][j][k]==inf)continue;
                dp[i+1][j][k]=min(dp[i][j][k],dp[i+1][j][k]);
                dp[i+1][j+a[i]][k+b[i]]=min(dp[i][j][k]+c[i],dp[i+1][j+a[i]][k+b[i]]);
            }
        }
    }
    ll mi=inf;
    ll k=1;
    while(k*max(ma,mb)<=401){
        mi=min(dp[n][k*ma][k*mb],mi);
        k++;
    }
    cout<<(mi==inf?-1:mi)<<endl;
}