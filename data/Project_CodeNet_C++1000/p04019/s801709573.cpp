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

void solve(){
    string s;
    cin>>s;
    ll n = s.size();
    ll x = 0,y=0,w=0,z=0;
    for(int i=  0;i<n;i++){
        if(s[i]=='E')x++;
        if(s[i]=='W')y++;
        if(s[i]=='N')z++;
        if(s[i]=='S')w++;
    }        
    if((x&&!y) || (!x && y) || (z && !w) || (!z && w)){
        cout<<"No\n";
        return;
    }
    

    else
        cout<<"Yes\n";
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
