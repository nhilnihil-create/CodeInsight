#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=1e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false); 

    int n,m,r;
    cin >> n >> m >> r;
    vector<int> town(r);
    rep(i,r) {
        cin >> town[i];
        --town[i];
    }
    vector<vector<int>> dp(n,vector<int>(n,INF));
    rep(i,m) {
        int a,b,c;
        cin >> a >> b >> c;
        dp[a-1][b-1]=c;
        dp[b-1][a-1]=c;
    }
    rep(i,n) {
        rep(j,n) {
            rep(k,n) dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
        }
    }
    int ans=INF;
    sort(town.begin(), town.end());
    do {
        int tans=0;
        rep(i,r-1) tans+=dp[town[i]][town[i+1]];
        ans=min(ans,tans);
    } while (next_permutation(town.begin(), town.end()));
    
    cout << ans << endl;

    return 0;
}
