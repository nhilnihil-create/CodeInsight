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
#define int ll
using namespace std;
 
const ll N =(2e5+5);
const ll MOD = 1e9+7;
const ll INF = LLONG_MAX;
const ll LOG = 29;
#define PI 3.141592653589793238 
 
 
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
void solve(){
    ll a,b,c;
    cin>>a>>b>>c;
    ll cnt = 0;
    while(cnt <= 1000000){
        if(a&1||b&1||c&1){
            cout<<cnt<<endl;
            return;
        }
        cnt++;
        ll tmpa = 0,tmpb= 0,tmpc = 0;
        tmpa += (b/2) + (c/2);
        tmpb += (a/2) + (c/2);
        tmpc += (a/2) + (b/2);
        a = tmpa;
        b=tmpb;
        c=tmpc;
    }
    cout<<"-1\n";

}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     
    ll t=1;
    while(t--){
        solve();
    }    
}