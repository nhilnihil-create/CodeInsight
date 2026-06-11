#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const ll MOD=1e9+7;


int main() {
    ios_base::sync_with_stdio(false);

    int n,a;
    cin >> n >> a;
    vector<int> x(n);
    rep(i,n) {
        cin >> x[i];
        x[i]-=a;
    }
    vector<vector<ll>> dp(n+1,vector<ll>(10000));
    int st=5000;
    dp[0][st]=1;
    rep(i,n) {
        rep(j,10000){
            if (j+x[i]>=0 && j+x[i]<10000) dp[i+1][j]+=dp[i][j]+dp[i][j+x[i]];
            else dp[i+1][j]+=dp[i][j];
        }
    }
    cout << dp[n][st]-1 << endl;

    return 0;
}