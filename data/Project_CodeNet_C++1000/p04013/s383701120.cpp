#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i = (n); i >= 0; i--)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(void)
{
    IOS
    const int X=50;
    int N, A;
    cin >> N >> A;
    vector<int> v(N);
    REP(i,N) cin >> v[i];

    vector<vector<vector<ll>>> dp(N+1,vector<vector<ll>>(N+1,vector<ll>(N*X+10)));
    dp[0][0][0] = 1;

    REP(i,N) {
        REP(j,i+1) {
            REP(k,j*X+1) {
                dp[i+1][j][k] += dp[i][j][k];
                dp[i+1][j+1][k+v[i]] += dp[i][j][k];
                //cerr << i+1 << " " << j << " " << k << " " << dp[i+1][j][k] << endl;
                //cerr << i+1 << ":" << j+1 << ":" << k+v[i] << ":" << dp[i+1][j+1][k+v[i]] << endl;
            }
        }
        //dp[i+1][1][v[i]]++;
    }
    

    ll ans = 0;
    FOR(i,1,N+1) {
        ans += dp[N][i][A*i];
        //cerr << i << " " << dp[N][i][A*i] << endl;
    }

    cout << ans << '\n';

    return 0;
}