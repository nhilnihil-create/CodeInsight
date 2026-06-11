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
const ll N = 2e5+9;
// const ll m = 1e9 + 7;
// const ll inf= 1e14;
const ll mod =163577857;
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pld pair<ld,ld>
ll powm(ll a, ll b) { a = a%mod;ll res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif     
    ll T= 1;
    // cin >> T;
    while(T--){
        ll n;cin>>n;
        ll p[n];
        for(int i = 0;i<n;i++){
            cin>>p[i];
        }
        ll b[n],a[n];
        for(int i = 0;i<n;i++){
            b[p[i]-1] = i+1;
            a[p[i]-1] = i+1;
        }
        for(int i = 1;i<n;i++){
            a[i]+=a[i-1];
        }
        for(int i = n-2;i>=0;i--){
            b[i]+=b[i+1];
        }
        for(int i = 0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<'\n';
        for(int i = 0;i<n;i++){
            cout<<b[i]<<" ";
        }
        cout<<'\n';


    }
   
}   