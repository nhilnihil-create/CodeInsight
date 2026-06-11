#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    ll x;
    cin>>n>>x;
    vector<ll> v;
    for(ll i=0;i<n;i++){
        ll k;
        cin>>k;
        v.pb(k);
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(v[i]>x){
            ans+=v[i]-x;
            v[i]=x;
        }
    }
    for(ll i=0;i<n-1;i++){
        if(v[i]+v[i+1]>x){
            ans+=v[i]+v[i+1]-x;
            v[i+1]=x-v[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
