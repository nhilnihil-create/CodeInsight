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



int main(){
    ios::sync_with_stdio(false);
    vector<vector<ll>> dp(55,vector<ll> (55,0));
    dp[0][0] = 1;
    for(int i=1; i<=50; i++){
        dp[i][0] = dp[i][i] = 1;
        for(int j=1; j<i; j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    int N,A,B;
    cin >> N >> A >> B;
    double ave = 0;
    vector<ll> v(N);
    map<ll,int> mp;
    for(int i=0; i<N; i++){
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(v.rbegin(),v.rend());
    for(int i=0; i<A; i++){
        ave += v[i];
    }
    ave /= A;
    ll ans = 0;
    map<ll,int> used;
    for(int i=0; i<A; i++){
        used[v[i]]++;
    }
    for(int i=A; i<=B; i++){
        ans += dp[mp[v[i-1]]][used[v[i-1]]];
        used[v[i-1]]++;
        if(v[0] != v[i]) break;
        // cout << mp[v[i-1]] << " " << used[v[i-1]] << "\n";
    }
    cout << fixed << setprecision(10) << ave << "\n";
    cout << ans << "\n";
    return 0;
}