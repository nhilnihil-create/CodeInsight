#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<functional>
#define rep(i,n,m) for(int i=(n);i<(int)(m);i++)
#define reps(i,n,m) for(int i=(n);i<=(int)(m);i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define fs first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define LB(a,x) lb(all(a), x) - a.begin()
#define UB(a,x) ub(all(a), x) - a.begin()
#define printfdouble(x) printf("%.20f\n",(x))
#define chartoint(c) (int)((c) - '0')
#define chartoll(c) (long long)((c) - '0')
#define MOD 1000000007
#define itn int
#define enld endl
#define ednl endl
#define icn cin
#define cotu cout
#define Endl endl
#define stirng string
using namespace std;
typedef long long ll;
const double pi = 3.141592653589793;
using Graph = vector<vector<int>>;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b){if(b<a){a=b; return 1;} return 0;}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll dp[205][205];
ll INF = 1e+18;
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int n,m,r;cin >> n >> m >> r;
    int rr[10];
    rep(i,0,r){
        cin >> rr[i];
        rr[i]--;
    }
    sort(rr,rr+r);

    Fill(dp, INF);
    rep(i,0,n) dp[i][i] = 0;
    rep(i,0,m){
        ll a,b,c;cin>>a>>b>>c;
        a--;b--;
        dp[a][b] = dp[b][a] = c;
    }

    rep(k,0,n){
        rep(i,0,n){
            rep(j,0,n){
                if(dp[i][k] == INF || dp[k][j] == INF) continue;
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    ll ans = 1e+18;
    do{
        ll tmp = 0;
        rep(i,0,r-1){
            tmp += dp[rr[i]][rr[i+1]];
        }
        chmin(ans, tmp);
    }while(next_permutation(rr,rr+r));

    cout << ans << endl;
    return 0;
}