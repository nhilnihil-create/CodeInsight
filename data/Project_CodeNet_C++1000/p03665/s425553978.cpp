#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<62;
const int IINF = 1000000000;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

int main(){
    int n, p; cin >> n >> p;

    vector<int> A(n);
    rep(i,n) cin >> A[i];

    vector<vector<ll>> dp(n+1, vector<ll>(2,0));
    dp[0][0] = 1;

    rep(i,n){
        rep(j,2){
            dp[i+1][j] += dp[i][j];
            dp[i+1][(j+A[i])%2] += dp[i][j];
        }
    }

    cout << dp[n][p] << endl;
    
}
