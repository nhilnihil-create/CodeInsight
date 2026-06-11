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
    cin>>n;
    vector<ll> v;
    v.pb(0);
    while(n--){
        ll k;
        cin>>k;
        v.pb(k);
    }
    sort(v.begin(),v.end());
    ll ans=0;
    for(ll i=1;i<v.size();i++){
        if(v[i]!=v[i-1]){
            ans+=1;
        }
    }
    cout<<ans-!(ans&1);
    return 0;
}
