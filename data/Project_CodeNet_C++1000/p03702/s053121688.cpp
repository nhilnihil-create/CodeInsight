#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define ld long double
#define FOR(i,a,n) for (int i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (int i=(n);i>=(a);--i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define MINUS(a) memset((a),-1,sizeof((a)))
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define all(g) g.begin(),g.end()
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// I am questioning life and universe and 
// everything else after looking at this

const ll MAXN = 1e5 + 10;
ll N,A,B;
ll h[MAXN];

bool check(ll val){
    vector<ll> ok;

    FOR(i,1,N) if(h[i] - B*val > 0) ok.push_back(h[i]-B*val);

    ll ans = 0;

    for(ll v:ok) ans += (v+(A-B-1))/(A-B);

    return (ans <= val);
}

void solve(){
    cin>>N>>A>>B;

    FOR(i,1,N) cin>>h[i];

    ll s = 1,e = *max_element(h+1,h+N+1);

    ll ans = e;

    while(s<=e){
        ll mid = (s+e)>>1;
        if(check(mid)) ans = mid,e = mid-1;
        else s = mid+1;
    }

    cout<<ans<<endl;
}   

signed main(){

   FastRead;    


    ll t;
    t = 1; 
    // cin>>t;
    FOR(i,1,t){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
}


