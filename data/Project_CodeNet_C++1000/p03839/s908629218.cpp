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
const ll N = 1e5+9;
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
ll a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif  
    int t = 1;
    // cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        ll ps[n],ps1[n];

        for(int i = 0;i<n;i++){
            cin>>a[i];
            ps[i] = max(0ll,a[i]);
            ps1[i] = a[i];
        }
        for(int i = 1;i<n;i++){
            ps[i]+=ps[i-1];
            ps1[i]+=ps1[i-1];
        }
        // for(int i = 0;i<n;i++){
        //     cout<<ps[i]<<" ";
        // }
        // cout<<'\n';
        // for(int i = 0;i<n;i++){
        //     cout<<ps1[i]<<" ";
        // }
        // cout<<'\n';
        ll ans = 0;
        for(int i = 0;i<n-k+1;i++){
            ll te =0;
            if(i==0){
                te = ps[n-1]-ps[i+k-1] +max(ps1[i+k-1],0ll);
            }
            else{
                te = ps[n-1] -ps[i+k-1]+ps[i-1]+max(ps1[i+k-1]-ps1[i-1],0ll);
            }
            ans = max(ans,te);

        }
        cout<<ans<<'\n';
    }
}