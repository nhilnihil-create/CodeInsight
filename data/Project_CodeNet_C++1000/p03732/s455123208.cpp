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

vector<ll> arr[4];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll w;
    cin>>n>>w;
    ll w1;
    cin>>w1;
    ll v;
    cin>>v;
    arr[0].pb(v);
    for(ll i=1;i<n;i++){
        ll c;
        cin>>c>>v;
        arr[c-w1].pb(v);
    }
    sort(arr[0].rbegin(),arr[0].rend());
    sort(arr[1].rbegin(),arr[1].rend());
    sort(arr[2].rbegin(),arr[2].rend());
    sort(arr[3].rbegin(),arr[3].rend());

    ll A=arr[0].size(),B=arr[1].size(),C=arr[2].size(),D=arr[3].size();
    vector<ll> sua(A+1,0);
    vector<ll> sub(B+1,0);
    vector<ll> suc(C+1,0);
    vector<ll> sud(D+1,0);
    for(ll i=1;i<=A;++i)sua[i]=sua[i-1]+arr[0][i-1];
    for(ll i=1;i<=B;++i)sub[i]=sub[i-1]+arr[1][i-1];
    for(ll i=1;i<=C;++i)suc[i]=suc[i-1]+arr[2][i-1];
    for(ll i=1;i<=D;++i)sud[i]=sud[i-1]+arr[3][i-1];

    ll ans=0;
    for(ll i=0;i<=A && i<=n;i++){
        for(ll j=0;j<=B && j<=n-i;j++){
            for(ll k=0;k<=C && k<=n-i-j;k++){
                for(ll l=0;l<=D && l<=n-i-j-k;l++){
                    if(w1*i+(w1+1)*j+(w1+2)*k+(w1+3)*l>w){
                        continue;
                    }
                    ans=max(ans,sua[i]+sub[j]+suc[k]+sud[l]);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
