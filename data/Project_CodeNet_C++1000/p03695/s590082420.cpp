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

int arr[8];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin>>n;
    vector<ll> v;
    ll count=0;
    for(ll i=0;i<n;i++){
        ll k;
        cin>>k;
        if(k<400){
            arr[0]+=1;
        }
        else if(k<800){
            arr[1]+=1;
        }
        else if(k<1200){
            arr[2]+=1;
        }
        else if(k<1600){
            arr[3]+=1;
        }
        else if(k<2000){
            arr[4]+=1;
        }
        else if(k<2400){
            arr[5]+=1;
        }
        else if(k<2800){
            arr[6]+=1;
        }
        else if(k<3200){
            arr[7]+=1;
        }
        if(k>=3200)
            count+=1;

        v.pb(k);
    }
    ll ans=0;
    for(int i=0;i<=7;i++){
        if(arr[i]>0){
            ans+=1;
        }
    }
    if(ans>0){
        cout<<ans<<' ';
    }
    else{
        cout<<1<<' ';
    }
    cout<<count+ans<<endl;
    return 0;
}
