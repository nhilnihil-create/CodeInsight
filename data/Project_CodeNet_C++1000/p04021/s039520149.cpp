#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define in insert
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
#define ffs fflush(stdout);
#define int ll
#define sz(x) (ll)x.size()
using namespace std;
 
 
const ll MOD = 1e9+7;
const ll INF = 1e9;
const ll LOG = 29;
#define PI 3.141592653589793238 
 
 
 


const ll N =(1e5+5);

ll fact[N];

long long binpow(long long a, long long b) {
     a%=MOD;    
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%MOD;
        a = (a * a)%MOD;
 
        
        b >>= 1;
    }
     res%=MOD;
    return res;
}
void ini(){
    fact[0] = 1;
    for(int i = 1;i < N;i++){
        fact[i] = (fact[i-1] * i)%MOD;
    }
}
ll ncr(ll n,ll r){
    ll ret = fact[n];
    ret = (ret * binpow(fact[r],MOD-2))%MOD;
    ret = (ret * binpow(fact[n-r],MOD-2))%MOD;
    return ret;
}
ll a[N];
map<ll,ll> idx;
ll b[N];
void solve(){
    ll n;
    cin >> n;

    for(int i =1;i<=n;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b+1,b+n+1);
    for(int i = 1;i<=n;i++){
        idx[b[i]] = i;
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        if((i&1) == (idx[a[i]] & 1)){
            continue;
        }
        ans += 1;
    }    
    cout << ans/2 << endl;
}


 
   
 
 
 /*
 2 3 4 5 6 
 3 6 10 15 21 
 4 10 20 35 56 
 5 15 35 70 126 
 6 21 56 126 252 
*/
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
       
 
    ll tt=1;
    while(tt--){
        solve();
    }    
}