#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip> // setprecision
#include <complex> // complex
#include <math.h> 
#include <climits> 
#include <assert.h>
#include <random>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 1e18;
constexpr int inf = 1e9;
constexpr ll mod = 1000000007;
constexpr ll mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[8] = {1, 0, -1, 0,1,1,-1,-1};
const int dy[8] = {0, 1, 0, -1,1,-1,1,-1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ---------------------------------------------------------------------------

int dp[50][500][500];

int main(){
    ios::sync_with_stdio(false);
    rep(i,50)rep(j,500)rep(k,500) dp[i][j][k] = inf;
    int N,A,B;
    cin >> N >> A >> B;
    vector<int> a(N),b(N),c(N);
    for(int i=0; i<N; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[0][0][0] = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<500; j++){
            for(int k=0; k<500; k++){
                if(dp[i][j][k] == inf) continue;
                chmin(dp[i+1][j][k],dp[i][j][k]);
                if(j+a[i] < 500 && k+b[i] < 500){
                    chmin(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k] + c[i]);
                }
            }
        }
    }
    int ans = inf;
    for(int i=1; i<500; i++){
        if(i*A>500 || i*B>500) break;
        chmin(ans,dp[N][i*A][i*B]);
    }
    if(ans == inf){
        cout << -1 << "\n";
    }else{
        cout << ans << "\n";
    }
    return 0;
}