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

const long long mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i=0;i<n;i++){
        int q;
        cin>>q;
        v.pb(q);
    }
    sort(v.begin(),v.end());
    ll ans=0;
    for(ll i=n-1;i>=n-k;i--){
        ans+=v[i];
    }
    cout<<ans<<endl;
    return 0;
}
