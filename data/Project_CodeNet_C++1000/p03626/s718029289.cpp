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
    int c=0;    // c=1 1 vertical c=2 2 horizontal

    string s1,s2;
    cin>>s1>>s2;

    ll ans=1;
    int i=0;
    if(s1[0]==s2[0]){
        ans*=3;
        c=1;
        i=1;
    }
    else{
        ans*=6;
        c=2;
        i=2;
    }
    for(i;i<n;){
        if(c==1){
            if(s1[i]==s2[i]){
                ans*=2;
                c=1;
                i+=1;
            }
            else if(s1[i]!=s2[i]){
                ans*=2;
                c=2;
                i+=2;
            }
        }
        else if(c==2){
            if(s1[i]==s2[i]){
                c=1;
                i+=1;
            }
            else{
                ans*=3;
                c=2;
                i+=2;
            }
        }
        if(ans>mod)
            ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}
