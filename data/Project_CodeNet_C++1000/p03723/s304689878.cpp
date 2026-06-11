#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()0
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=100009;
 
// Happy Coding!

bool isOdd(ll a,ll b,ll c){
    return a&1 || b&1 || c&1 ;
}
ll _find(ll a,ll b,ll c){
    if(isOdd(a,b,c)){
        return 0;
    }
    ll x=(b+c)/2;
    ll y=(a+c)/2;
    ll z=(a+b)/2;
    vll p={a,b,c};
    vll q={x,y,z};
    sort(all(p));
    sort(all(q));
    return p==q?INT_MAX:1+_find(x,y,z);
}

void solve(){
    
    ll a,b,c;
    cin>>a>>b>>c;
    
    ll ans=_find(a,b,c);
    if(ans==INT_MAX){ans=-1;}
    cout<<ans<<endl;
}

 
int main() {
    faster;
    int t=1;
    // cin>>t;
    
    while(t-->0){
        solve();
    }
	return 0;
}