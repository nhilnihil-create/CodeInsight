#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000000
#define MAX 200001
#define MOD 1000000007

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};


int main(){
    int N, Ma, Mb;
    ll ans = INF;
    cin >> N >> Ma >> Mb;
    vector<tuple<int,int,int>> yakuhin(N);
    rep(i,N){
        int a, b, c;
        cin >> a >> b >> c;
        yakuhin[i] = {a, b, c};
    }
    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(401, vector<ll>(401, INF)));
    dp[0][0][0] = 0;
    rep(i,N){
        int a = get<0>(yakuhin[i]);
        int b = get<1>(yakuhin[i]);
        int c = get<2>(yakuhin[i]);
        rep(j,401)rep(k,401){
            if(j-a>=0 && k-b>=0) dp[i+1][j][k] = min(dp[i][j][k], dp[i][j-a][k-b] + c);
            else dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
        }
    }
    int d_a = Ma;
    int d_b = Mb;
    while(Ma < 401 && Mb < 401){
        ans = min(ans,dp[N][Ma][Mb]);
        Ma += d_a;
        Mb += d_b;
    }
    if(ans == INF) ans = -1;
    cout << ans << endl;
}

