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
        ll n,x;cin>>n>>x;
        if(n==2){
            if(x==2){
                cout<<"Yes\n 1\n2\n3\n";
            }
            else{
                cout<<"No\n";
            }
        }
        else if(x == 1 || x == (2*n-1)){
            
                cout<<"No\n";
        }
        else{

            cout<<"Yes\n";
            bool used[2*n];
            ll a[2*n];
            memset(used,0,sizeof(used));
            n--;
            memset(a,0,sizeof(a));
            if(x==2){
                a[n-1] = x+1;
                a[n] = x;
                a[n+1] = x-1;
                a[n+2] = x+2;
                used[x] = 1;used[x+1] = 1;
                used[x-1] = 1;used[x+2] = 1;
            }
            else{

                a[n-1] = x-1;
                a[n] = x;
                a[n+1] = x+1;
                a[n+2] = x-2;
                used[x] = 1;used[x+1] = 1;
                used[x-1] = 1;used[x-2] = 1;

            }
            n++;
            std::vector<ll> un;
            for(int i = 1;i<2*n;i++){
                if(!used[i]){
                    un.pb(i);
                }
            }
            ll in = 0;
            for(int i = 0;i<2*n-1;i++){
                if(a[i] == 0){
                    cout<<un[in]<<'\n';
                    in++;
                }
                else{
                    cout<<a[i]<<'\n';
                }
            }
        }

    }
   
}   