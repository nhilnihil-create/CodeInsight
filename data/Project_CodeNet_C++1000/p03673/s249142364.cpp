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
    int n;
    cin>>n;
    vector<ll> v;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        v.pb(a);
    }
    if((n&1)==0){
        for(int i=n-1;i>=0;i-=2){
            cout<<v[i]<<' ';
        }
        for(int i=0;i<n;i+=2){
            cout<<v[i]<<' ';
        }
    }
    else{

        for(int i=n-1;i>=0;i-=2){
            cout<<v[i]<<' ';
        }
        for(int i=1;i<n;i+=2){
            cout<<v[i]<<' ';
        }
    }
    return 0;
}
