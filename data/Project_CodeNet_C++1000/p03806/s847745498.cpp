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

int dp[41][401][401];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ma,mb;
    cin>>n>>ma>>mb;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=400;j++){
            for(int k=0;k<=400;k++){
                dp[i][j][k]=5000;
            }
        }
    }
    for(int i=0;i<=n;i++){
        dp[i][0][0]=0;
    }

    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        for(int j=0;j<=400-a;j++){
            for(int k=0;k<=400-b;k++){
                if(dp[i][j+a][k+b]>dp[i-1][j][k]+c){
                    for(int t=i;t<=n;t++){
                        dp[t][j+a][k+b]=dp[i-1][j][k]+c;
                    }
                }
            }
        }
    }

    ll ans=5000;
    for(int i=1;(i*ma<401)&&(i*mb<401);i++){
        int count=dp[n][i*ma][i*mb];
        if(count<ans)
            ans=count;
    }

    if(ans==5000){
        cout<<-1;
    }
    else{
        cout<<ans<<endl;
    }
    return 0;
}
