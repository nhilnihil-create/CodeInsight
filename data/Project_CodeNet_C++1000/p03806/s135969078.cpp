#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define LB(a,x) lb(all(a),x)-a.begin()
#define UB(a,x) ub(all(a),x)-a.begin()
#define mod 1000000007
//#define mod 998244353
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline void out(T a){ cout << a << '\n'; }
void YN(bool ok){if(ok) cout << "Yes" << endl; else cout << "No" << endl;}
//void YN(bool ok){if(ok) cout << "YES" << endl; else cout << "NO" << endl;}


const ll INF=1e18;
const int mx=200005;

ll dp[45][405][405];

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll n,ma,mb;
    cin>>n>>ma>>mb;
    V<ll> a(n),b(n),c(n);
    rep(i,n) cin>>a[i]>>b[i]>>c[i];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=400;j++){
            for(int k=0;k<=400;k++){
                dp[i][j][k]=INF;
            }
        }
    }
    dp[0][0][0]=0;
    rep(i,n){
        for(int j=0;j<=400;j++){
            for(int k=0;k<=400;k++){
                chmin(dp[i+1][j][k],dp[i][j][k]);
                if(j-a[i]>=0&&k-b[i]>=0){
                    chmin(dp[i+1][j][k],dp[i][j-a[i]][k-b[i]]+c[i]);
                }
            }
        }
    }
    ll ans=INF;
    for(ll i=1;i*ma<=400&&i*mb<=400;i++) chmin(ans,dp[n][i*ma][i*mb]);
    if(ans==INF) ans=-1;
    out(ans);
}