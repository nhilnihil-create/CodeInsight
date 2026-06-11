#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define ppll pair<ll,pll>
#define pdd pair<double,double>
#define vii vector<int>
#define vll vector<ll>
#define mat vector<vector<ll>>
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define sz(x) (ll) (x).size()
#define pq priority_queue<ll>
#define pqg priority_queue<ll,vector<ll>,greater<ll>>
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end())
// #define int ll
// #define ll int
using namespace std;
const ll INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
// const ll mod = 998244353;
const ll MAX = 2100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[8] ={1,0,-1,0,1,-1,1,-1};
ll dy[8] ={0,1,0,-1,1,-1,-1,1};
 
template<class T> 
inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> 
inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



short cnt[5010][5010];
short cnt2[5010][5010];
int n,k;
int a[5001];


void solve() {
    cin>>n>>k;
    rep(i,n) cin>>a[i];
    // vii dp[5010];
    vii dp2[5010];
    cnt[0][0]=1;
    for(int i=0;i<n;i++){
        // dp[i+1]=dp[i];
        for(int j=0;j<=k;j++){
            if(cnt[i][j]==0) continue;
            cnt[i+1][j]=1;
            if(j + a[i] > k) continue;
            cnt[i+1][j+a[i]]=1;
        }
    }
    cnt2[n][0]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=k;j++){
            if(cnt2[i+1][j]==0) continue;
            cnt2[i][j]=1;
            if(j + a[i] > k) continue;
            cnt2[i][j+a[i]]=1;
        }
    }
    
    // rep(i,n+1){
    //     for(int j=0;j<=k;j++){
    //         if(cnt[i][j]>0){
    //             dp[i].pb(j);
    //         }
    //     }
    // }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<=k;j++){
            if(cnt2[i][j]==1){
                dp2[i].pb(j);
            }
        }
    }

    // rep(i,n+1){
    //     for(ll j : dp[i]) cout<<j<<" ";
    //     cout<<endl;
    // }
    // rep(i,n+1){
    //     for(ll j : dp2[i]) cout<<j<<" ";
    //     cout<<endl;
    // }

    int ans=0;
    for(int i=0;i<n;i++){
        int x = max(0, k-a[i]);
        bool ok = true;
        for(int j=0;j<=k;j++) {
            if(cnt[i][j]==0) continue;
            // cout<<"x-j:"<<x-j<<" ";
            auto index = lower_bound(dp2[i+1].begin(), dp2[i+1].end(), x - j);
            if(index== dp2[i+1].end()){
                // cout<<endl;
                continue;
            }
            int y = *index;
            // cout<<i<<" "<<j<<" "<<y<<" "<<endl;
            if(j + y >= k) continue;
            ok = false;
            if(!ok) break;
        }
        if(ok) ans++;
    }
    cout<<ans<<endl;
}


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);


    solve(); 


    return 0;
}
