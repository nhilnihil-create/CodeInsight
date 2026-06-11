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

const int N = 100005;

ll h[N];
ll n, a, b;

bool ck(ll x){
    ll mx = 0;
    ll cnt = 0;
    FOR(i,1,n){
        ll temp = max(0LL, h[i] - b * x);
        cnt += (temp + a - b -1) / (a - b);
    }
    return cnt <= x;
}

int main(){
    IOS
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cin >> n >> a >> b;
    FOR(i,1,n){
        cin >> h[i];
    }
    ll l = 0, r = 1000000000;
    ll ans;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(ck(mid)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans;


    cerr<<endl<<endl<<"Time: "<<fixed<<setprecision(12)<<(long double)(clock()-clk)/CLOCKS_PER_SEC<<" ms"<<endl<<endl;
 
    return 0;
}