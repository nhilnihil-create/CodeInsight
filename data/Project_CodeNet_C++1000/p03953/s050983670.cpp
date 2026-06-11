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
        ll x[n];
        for(int i = 0;i<n;i++){
            cin>>x[i];
        }
        ll m,k;cin>>m>>k;
        ll b[m];
        for(int i = 0;i<m;i++){
            cin>>b[i];
        }
        ll d[n-1],orig[n-1];
        for(int i = 0;i<n-1;i++){
            d[i] = x[i+1]-x[i];
            orig[i] = i;
            // cout<<d[i]<<" ";
        }
        // cout<<'\n';

        for(int i = 0;i<m;i++){
            swap(orig[b[i]-1],orig[b[i]-2]);
        }
        ll g[n-1];
        for(int i = 0;i<n-1;i++){
            g[orig[i]]= i;
            // cout<<orig[i]<<" ";
        }
        // cout<<'\n';
        // for(int i = 0;i<n-1;i++){
        //     cout<<g[i]<<" ";
        // }
        // cout<<'\n';
        bool vis[n-1];
        memset(vis,0,sizeof(vis));
        ll ind[n-1],set[n-1];
        std::vector<std::vector<ll>> ch;
        ll cs = 0;
        for(int i = 0;i<n-1;i++){
            if(!vis[i]){
                ch.pb({});
                vis[i] = 1;
                ind[i] = 0;
                set[i] = cs;
                ch[cs].pb(i);
                if(orig[i]!=i){
                    ll c = orig[i];
                    ind[c] = 1;
                    while(!vis[c]){
                        set[c] = cs;
                        vis[c] = 1;
                        ch[cs].pb(c);
                        if(!vis[orig[c]]){
                            ind[orig[c]] = ind[c]+1;
                        }
                        c = orig[c];

                    }
                }
                    cs++;

            }
        }
        // cout<<cs<<'\n';
        // for(int i = 0;i<cs;i++){
        //     for(auto j:ch[i]){
        //         cout<<j<<" ";
        //     }
        //     cout<<'\n';

        // }
        // for(auto i:ch[0]){
        //     cout<<i<<" ";
        // }
        // cout<<'\n';
        ll nd[n-1];
        // for(int i = 0;i<n-1;i++){
        //     cout<<ind[i]<<" ";
        // }
        // cout<<'\n';
        for(int i = 0;i<n-1;i++){

            ll j = ((ll)ind[i]+k)%ch[set[i]].size();
            // cout<<j<<'\n';
            nd[i] = d[ ch[ set[i] ] [ j]];   
            // cout<<nd[i]<<" ";
        }
        // cout<<'\n';
        ll nx[n];
        nx[0] = x[0];
        for(int i = 0;i<n-1;i++){
            // cout<<nd[i]<<" ";
            nx[i+1] = nx[i]+nd[i];
        }
        for(int i = 0;i<n;i++){
            cout<<nx[i]<<'\n';
        }

    }
   
}   