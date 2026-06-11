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
        ll H,W,h,w;cin>>H>>W>>h>>w;
        if(H%h == 0 && W%w==0){
            cout<<"No\n";
        }
        else{
            ll ans[H][W];
            ll v = 1000*(h*w-1);v++;
            cout<<"Yes\n";
            for(int i = 0;i<H;i++){
                for(int j = 0;j<W;j++){
                    ans[i][j] = 1000;
                    if((i+1)%h==0 && (j+1)%w==0){
                        ans[i][j] = -v;
                    }
                }
            } 
            for(int i = 0;i<H;i++){
                for(int j = 0;j<W;j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<'\n';
            }
        }

    }
}