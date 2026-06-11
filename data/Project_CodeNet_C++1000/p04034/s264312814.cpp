#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>
// using namespace __gnu_pbds;
using namespace std;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
//     tree_order_statistics_node_update>;
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
typedef long long int ll;
typedef long double ld;
const ll N = 1e5+1;
// const ll m = 1e9 + 7;
// const ll inf= 1e14;
const ll mod =998244353;
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define pld pair<ld,ld>
ll powm(ll a, ll b) { a = a%mod;ll res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
bool a[N];
ll ct[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif  
    int t = 1;
    // cin>>t;
    memset(a,0,sizeof(a));
    while(t--){
        ll n,m;cin>>n>>m;
        for(int i = 0;i<n;i++){
            ct[i] = 1;
        }
        a[0] = 1;
        for(int i = 0;i<m;i++){
            ll x,y;cin>>x>>y;x--;y--;
            if(a[x]){
                if(ct[x]>1){
                    a[y] = 1;
                }
                else{
                    a[y] = 1;
                    a[x] = 0;
                }
            }
            ct[x]--;
            ct[y]++;
        }
        ll ans = 0;
        for(int i = 0;i<n;i++){
            ans+=a[i];
        }
        cout<<ans<<'\n';
    }
}