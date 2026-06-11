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
const long long inf = 1e18;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vi v;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v.pb(k);
    }
    sort(v.rbegin(),v.rend());
    v.pb(-1);

    int count=1;
    int a=0;
    ll ans=1;
    int t=v[0];

    for(int i=1;i<=n;i++){
        if(v[i]==t){
            count+=1;
            if(count==2 || count==4){
                ans*=t;
                a+=1;
                if(a==2){
                    break;
                }
            }
        }
        else{
            t=v[i];
            count=1;
        }
    }
    if(ans>1)
        cout<<ans<<endl;
    else if(ans==1 && a==2)
        cout<<1<<endl;
    else
        cout<<0<<endl;
    return 0;
}
