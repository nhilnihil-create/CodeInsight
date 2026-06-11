#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

int dp[50][500][500];

int main(){
    int N,Ma,Mb; cin >> N >> Ma >> Mb;
    vector<int> a(N),b(N),c(N);
    rep(i,N){
        cin >> a[i] >> b[i] >> c[i];
    }
    int ans = INF;
    rep(i,50)rep(j,500)rep(k,500) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    rep(i,N)rep(j,500)rep(k,500){
        if(j-a[i] >= 0 && k-b[i] >= 0) dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j-a[i]][k-b[i]]+c[i]);
        dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]);
        if(j*Mb == k*Ma && j != 0 && k != 0) ans = min(ans,dp[i+1][j][k]);
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}
