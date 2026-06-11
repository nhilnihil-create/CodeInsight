#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define ve vector
#define pq priority_queue
#define vi vector<int>
#define vl vector<long long>
#define vii vector<vector<int>>
using namespace std;
using ll = long long;
using ld = long double;
const ll mod = 1000000007;
#define P pair<int,int>


int main()
{
    int N,W;
    cin >> N >> W;
    vi w(N),v(N);
    rep(i,N) cin >> w[i] >> v[i];
    
    int w0 = w[0]-1;
    rep(i,N) w[i]-=w0;
    
    
    ve<ve<ve<int>>> dp(N+1,ve<ve<int>>(400,ve<int>(101,0)));
    
    rep(i,N) rep(j,400) rep(k,100){
        if(w[i] <= j){
            if(dp[i][j][k+1] < dp[i][j-w[i]][k]+v[i]){
                dp[i+1][j][k+1] = dp[i][j-w[i]][k]+v[i];
            }else{
                dp[i+1][j][k+1] = dp[i][j][k+1];
            }
        }else{
            dp[i+1][j][k+1] = dp[i][j][k+1];
        }
    }
    
    

    ll ans = 0;
    rep(j,400) rep(k,101){
        ll a = (ll)j + (ll)k*w0;
        if(a <= (ll)W) ans = max(ans,(ll)dp[N][j][k]);
    }
    out(ans);

    return 0;
}
