#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define pair_ordered_set tree< pair<ll,ll> , null_type,less< pair<ll,ll> >, rb_tree_tag,tree_order_statistics_node_update>
pair_ordered_set st;
const ll N=2e5+5;
ll n,k,ans,a[N];
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(ll i=1;i<=n;i++)cin>>a[i],a[i]-=k,a[i]+=a[i-1];
    for(ll i=0;i<=n;i++){
        ll cnt = st.order_of_key({a[i]+1,-1});
        ans+=cnt;
        st.insert({a[i],i});
    }
    cout<<ans;
}


