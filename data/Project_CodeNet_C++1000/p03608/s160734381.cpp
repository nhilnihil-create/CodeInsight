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
    int n,m,r;
    cin>>n>>m>>r;
    vi rarr;
    ll d[n+3][n+3];
    for(int i=0;i<r;i++){
        int k;
        cin>>k;
        rarr.pb(k);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                d[i][j]=0;
            }
            else{
                d[i][j]=inf;
            }

        }
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(d[a][b]>c){
            d[a][b]=c;
            d[b][a]=c;
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(d[i][j]>d[i][k]+d[k][j]){
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }
    ll ans=inf;
    sort(rarr.begin(), rarr.end());
    do {
        ll count=0;
        for(int i=0;i<r-1;i++){
            count+=d[rarr[i]][rarr[i+1]];
        }
        if(count<ans)
            ans=count;

    }while(next_permutation(rarr.begin(),rarr.end()));

    cout<<ans<<endl;
    return 0;
}
