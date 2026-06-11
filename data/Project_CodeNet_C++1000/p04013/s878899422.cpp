#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define mp make_pair
#define bit(n) (1LL<<(n))
#define F first
#define S second
#define debug(x) cerr << x << endl
#define Complex complex<double>
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const ll INF = 1LL<<60;
const ll mod = (int)1e9 + 7;

int main() {
    ll n,a;
    cin >> n >> a;
    ll dp[51][2510]={};
    dp[0][0]=1;
    ll ans=0;
    rep(i,n){
        ll x;
        cin >> x;
       	for(int j=49;j>=0;j--){
            rep(k,2451){
                dp[j+1][k+x]+=dp[j][k];
                if((j+1)*a==k+x)ans+=dp[j][k];
            }
        }
      	debug(ans);
    }
    cout << ans;

    
}