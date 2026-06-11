#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define endl "\n"
#define pll pair<ll,ll>
#define all(x) (x).begin() , (x).end()
#define f first
#define s second
#define pr(x) cout<<x<<endl;
#define pr2(x,y) cout<<x<<" "<<y<<endl;
#define pr3(x,y,z) cout<<x<<" "<<y<<endl;
#define prv(v) for(auto x:v) cout<<x<<" ";
using namespace std;
 
const ll N =(1e5+5);
const ll MOD = 1e9+7;
const ll INF = 1e16;
const ll LOG = 29;

long long binpow(long long a, long long b) {
     a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%MOD ;
        a = (a * a)%MOD ;

        
        b >>= 1;
    }
    res%=MOD;
    return res;
}
ll dp2[404][404];
ll dp[404][404];
void solve(){
    ll n;
    cin>>n;
    vll a(n);
    for(int i= 0;i<n;i++){
        cin>>a[i];
    }
    ll l,q;
    cin>>l>>q;
    ll dp[25][n];
    for(int i= 0;i<n;i++){
        auto it = upper_bound(all(a),a[i]+l);
        it--;
        dp[0][i] = distance(a.begin(),it);   
    }
    for(int i = 1;i<25;i++){
        for(int j = 0;j<n;j++){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }

    while(q--){
        ll a,b;
        cin>>a>>b;
        --a;
        --b;
        if(a>b)swap(a,b);
        ll ans = 0;
        for(ll i =24;i>=0;i--){
            if(dp[i][a] < b){
                ans |= (1ll<<i);
                a = dp[i][a];
            }
        }
        ans++;
        cout<<ans<<endl;
    }
}






int main()
{
    ios_base::sync_with_stdio(0);
     cin.tie(NULL);
     
    ll t=1;
    while(t--){
        solve();
    }
     
 
 
    return 0;     
    
        
}