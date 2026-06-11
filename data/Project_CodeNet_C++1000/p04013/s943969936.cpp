#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const long double PI = (acos(-1));
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
static const int MAX = 50*50;
int main(){
    int n, a, ans = 0,sum; sc(n), sc(a);
    vector<int> x(n);
    vector<vector<ll> > dp(n+1, vector<ll>(2*MAX+1,0));
    rep(i, 0, n) sc(x[i]), x[i] -= a;
    dp[0][MAX] = 1;
    rep(i, 1, n+1){
        rep(j, 0, 2*MAX+1){
            if (j-x[i-1]<0 || j-x[i-1]>2*MAX){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] + dp[i-1][j-x[i-1]];
            }
        }
    }
    cout << dp[n][MAX] - 1 << endl;
    return 0;
}