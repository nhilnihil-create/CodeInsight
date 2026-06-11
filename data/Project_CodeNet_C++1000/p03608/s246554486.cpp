#include<bits/stdc++.h>
using namespace std;

const int INF=1e9;
int main() {
    int n,m,r;
    cin >> n >> m >> r;
    vector<vector<int>> G(n+1, vector<int>(n+1,INF));
    vector<int> R(r);
    for ( int i=0; i<r; i++ ) {
        cin >> R[i];
        // R[i]--;
    }
    for ( int i=0; i<=n; i++ ) G[i][i]=0;
    for ( int i=0; i<m; i++ ) {
        int a,b,c;
        cin >> a >> b >> c;
        // --a; --b;
        G[a][b]=c;
        G[b][a]=c;
    }
    for ( int k=1; k<=n; k++ ) 
        for ( int i=1; i<=n; i++ )
            for ( int j=1; j<=n; j++ )
                G[i][j]=min(G[i][j],G[i][k]+G[k][j]);

    vector<vector<int>> dp(1<<r, vector<int>(n+1,INF));
    // for ( int i=0; i<n; i++ ) dp[1<<i][i]=0;
    for ( int i=0; i<=n; i++ ) dp[0][i]=0;
    for ( int i=0; i<r; i++ ) dp[1<<i][R[i]]=0;
    for ( int mask=1; mask<(1<<r); mask++ ) {
        for ( int i=0; i<r; i++ ) {
            if ( mask>>i&1 ) {
                for ( int j=0; j<r; j++ ) {
                    dp[mask][R[i]]=min(dp[mask][R[i]],dp[mask^(1<<i)][R[j]]+G[R[j]][R[i]]);
                }                
            }
        }
    }
    int mi=INF;
    for ( int i=1; i<=n; i++ ) {
        mi=min(mi,dp[(1<<r)-1][i]);
    }
    cout << mi << '\n';
    return 0;
}
