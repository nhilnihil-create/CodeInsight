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
    int n;
    cin>>n;
    vector<ll> v;
    for(int i=0;i<n;i++){
        ll k;
        cin>>k;
        v.pb(k);
    }
    sort(v.begin(),v.end());
    ll ans=1;
    if((n&1)==0){
        for(int i=0;i<=n-2;i+=2){
            if(v[i]!=i+1){
                ans=0;
                break;
            }
            if(v[i+1]!=i+1){
                ans=0;
                break;
            }
        }
        if(ans==1){
            for(int i=0;i<(n>>1);i++){
                ans<<=1;
                ans=ans%1000000007;
            }
        }
        cout<<ans<<endl;
    }
    else{
        if(v[0]!=0)
            ans=0;
        for(int i=1;i<=n-2;i+=2){
            if(v[i]!=i+1){
                ans=0;
                break;
            }
            if(v[i+1]!=i+1){
                ans=0;
                break;
            }
        }
        if(ans==1){
            for(int i=0;i<(n>>1);i++){
                ans<<=1;
                ans=ans%1000000007;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
