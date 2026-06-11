// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x) cout << #x << ' ' << '=' << ' ' << (x) << endl;
#define fs first
#define sc second
#define pb push_back
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int,int,int> T;
typedef priority_queue<int> PQI;
typedef priority_queue<P> PQP;
const vector<int> dx = {0, -1, 0, 1, 1, 1, -1, -1};
const vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
const int MOD = (1000000007);
// const int MOD = (998244353);
// const int INF = (1 << 30);
const int INF = (1LL << 60);
const double EPS = (1 >> 30);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}

using Graph = vector<vector<P>>;
using vvec = vector<vector<int>>;
using vec = vector<int>;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    //---------------------------------------------
    
    int n,a;
    cin>>n>>a;
    vector<int> x(n);
    REP(i,n) cin >> x[i];
    rep(i,n){
        x[i]-=a;
    }
    int dp[1000][1000];
    rep(i,1000){
        rep(j,1000){
            dp[i][j]=0;
        }
    }
    int l = 500;
    // 合計値　枚数
    dp[ x[0]+ l ][ 0 ]+=1;
    dp[   0 + l ][ 0 ]+=1;
    rep(i,n-1){
        rep(j,1000){
            int cnt = dp[j][i];
            dp[j][i+1]+=dp[j][i];
            if(0<=j+x[i+1]&&j+x[i+1]<1000){
                dp[j+x[i+1]][i+1]+=dp[j][i];
            }
        }
    }

    

    cout<<dp[0+l][n-1]-1<<endl;

    
}