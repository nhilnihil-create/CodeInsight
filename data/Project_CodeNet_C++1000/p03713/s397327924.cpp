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
    ll h,w;
    cin>>h>>w;
    ll sa,sb,sc;
    ll ans=h*w;
    for(ll i=1;i<=h-2;i++){ // cut horizontally
        sa=i*w;
        ll k=(h-i)/2;
        sb=k*w;
        sc=(h-i-k)*w;
        ll s=max(max(sa,sb),sc)-min(min(sa,sb),sc);
        if(ans>s){
            ans=s;
        }
    }
    for(ll i=1;i<=h-1;i++){ // cut vertically
        sa=i*w;
        ll k=w/2;
        sb=k*(h-i);
        sc=(h-i)*(w-k);
        ll s=max(max(sa,sb),sc)-min(min(sa,sb),sc);
        if(ans>s){
            ans=s;
        }
    }
    swap(h,w);
    for(ll i=1;i<=h-2;i++){ // cut horizontally
        sa=i*w;
        ll k=(h-i)/2;
        sb=k*w;
        sc=(h-i-k)*w;
        ll s=max(max(sa,sb),sc)-min(min(sa,sb),sc);
        if(ans>s){
            ans=s;
        }
    }
    for(ll i=1;i<=h-1;i++){ // cut vertically
        sa=i*w;
        ll k=w/2;
        sb=k*(h-i);
        sc=(h-i)*(w-k);
        ll s=max(max(sa,sb),sc)-min(min(sa,sb),sc);
        if(ans>s){
            ans=s;
        }
    }
    cout<<ans<<endl;
    return 0;
}
