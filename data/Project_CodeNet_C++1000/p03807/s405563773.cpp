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
#define ffs fflush(stdout);
using namespace std;
 
const ll N =(2e5+5);
const ll MOD = 998244353;
const ll INF = LLONG_MAX;
const ll LOG = 29;
 
long long binpow(long long a, long long b) {
    // a%=MOD;    
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a);
        a = (a * a) ;
 
        
        b >>= 1;
    }
    //res;
    return res;
} 

ll div(ll n){
    set<ll> se;
    for(int i =1;i<=sqrt(n);i++){
        if(n%i==0){
            se.insert(i);
            se.insert(n/i);
        }
    }
    return se.size()*1ll;
}

void solve(){
    ll n;
    cin>>n;
    ll a[n+1];
    ll e=0,o = 0;
    for(int i =1;i<=n;i++){
        cin>>a[i];
        if(a[i]&1)o+=a[i];
        else e+=a[i];
    }    
    if(o&1){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
}
 
 
int main(){
    ios_base::sync_with_stdio(0);
     cin.tie(NULL);
     
    ll t=1;
    while(t--){
        solve();
    }
     
 
 
    return 0;     
    
        
}
