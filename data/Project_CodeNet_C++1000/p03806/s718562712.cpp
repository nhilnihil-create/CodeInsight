#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define MOD2 998244353
#define pb emplace_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define sz(x) (ll)x.size()
#define F first
#define S second
#define FOR(i,a,b) for(ll i=a;i<=b;++i)
#define ROF(i,a,b) for(ll i=a;i>=b;--i)
#define trace(x) cerr<<#x<<": "<<x<<'\n';
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
auto clk=clock();
 
ll mexp(ll a, ll b, ll m){
    ll ans=1;
    a%=m;
    while(b){
        if(b&1) ans=ans*a%m;
        b>>=1;
        a=a*a%m;
    }
    return ans;
}

const int N = 50;
int a[N], b[N], c[N];
int dp[N][404][404];

int main(){
    IOS
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int n, ma, mb;
    cin >> n >> ma >> mb;
    FOR(i,1,n){
        cin >> a[i] >> b[i] >> c[i];
    }
    FOR(i,0,n){
        FOR(j,0,400){
            FOR(k,0,400){
                dp[i][j][k] = 5000;
            }
        }
    }
    dp[0][0][0] = 0;
    FOR(i,1,n){
        FOR(j,0,400){
            FOR(k,0,400){
                if(dp[i-1][j][k] == 5000){
                    continue;
                }
                dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);
                dp[i][j+a[i]][k+b[i]] = min(dp[i][j+a[i]][k+b[i]], dp[i-1][j][k] + c[i]);
            }
        }
    }
    int ans = 5000;
    FOR(j,1,400){
        FOR(k,1,400){
            if(j * mb == k * ma){
                ans = min(ans, dp[n][j][k]);
            }   
        }
    }
    if(ans == 5000){
        ans = -1;
    }
    cout << ans;

    cerr<<endl<<endl<<"Time: "<<fixed<<setprecision(12)<<(long double)(clock()-clk)/CLOCKS_PER_SEC<<" ms"<<endl<<endl;
 
    return 0;
}