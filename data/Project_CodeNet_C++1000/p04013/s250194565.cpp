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

ll dp[51][51][2501];    // 1 to j , k cards , sum=s

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a;
    cin>>n>>a;
    vector<int> v;
    v.pb(0);
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        v.pb(c);
    }
    dp[0][0][0]=1;

    for(int s=0;s<=2500;s++){
        for(int k=0;k<=n;k++){
            for(int j=1;j<=n;j++){
                if(s<v[j]){
                    dp[j][k][s]=dp[j-1][k][s];
                }
                else if(s>=v[j] && k>=1){
                    dp[j][k][s]=dp[j-1][k][s]+dp[j-1][k-1][s-v[j]];
                }
            }
        }
    }

    ll ans=0;
    for(ll i=1;i<=n;i++){
        ans+=dp[n][i][a*i];
    }
    cout<<ans<<endl;
    return 0;
}
