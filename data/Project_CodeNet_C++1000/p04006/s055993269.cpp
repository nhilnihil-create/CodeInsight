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
const ll m = 1e9 + 7;
const ll MAXN = 2e3 + 9;

const ll inf= 1e14;
const ll mod =163577857;
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pld pair<ld,ld>
ll powm(ll a, ll b) { a = a%mod;ll res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
ll lo[MAXN+1];
ll st[MAXN][MAXN + 1],n;
ll qr(ll L,ll R){
    ll j = lo[R - L + 1];
    ll minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
    return minimum;
}
ll mi(ll i,ll k){
    if((i-k)<0){
        ll ans = min(qr(0,i),qr(n-(k-i),n-1));
        return ans;
    }
    else{
        ll ans = qr(i-k,i);
        return ans;
    }
}
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
    lo[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        lo[i] = lo[i/2] + 1;
    while(T--){
        ll K,x;cin>>n>>x;
        ll a[n];
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        K = lo[n];

        for (int i = 0; i < n; i++)
            st[i][0] = a[i];

        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);

        ll ans = inf;
        for(int k = 0;k<=n;k++){
            ll te = k*x;
            for(int i = 0;i<n;i++){
                te+=mi(i,k);
            }
            ans = min(ans,te);
        }
        cout<<ans<<'\n';
    }
   
}   