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

ll arr[100001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,k;
    cin>>n>>k;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        arr[a]+=b;
    }
    ll count=0;
    for(ll i=1;;i++){
        count+=arr[i];
        if(count>=k){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
