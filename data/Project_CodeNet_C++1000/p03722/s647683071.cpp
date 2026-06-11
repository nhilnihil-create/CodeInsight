#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
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
    int n,m;
    cin>>n>>m;
    ll dist[n+1];
    ll a[m],b[m],c[m];
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i]>>c[i];
        c[i]=-c[i];
    }
    for(int i=1;i<=n;i++){
        dist[i]=inf;
    }
    dist[1]=0;

    for(int t=0;t<n-1;t++){
        for(int i=0;i<m;i++){
            if(dist[a[i]]==inf)
                continue;
            if(dist[b[i]]>dist[a[i]]+c[i]){
                dist[b[i]]=dist[a[i]]+c[i];
            }
        }
    }

    ll ans=dist[n];

    bool negative[n+1];
    for(int i=1;i<=n;i++){
        negative[i]=false;
    }

   
        for(int i=0;i<m;i++){
            if(dist[a[i]]==inf)
                continue;
            if(dist[b[i]]>dist[a[i]]+c[i]){
                dist[b[i]]=dist[a[i]]+c[i];
                negative[b[i]]=true;
            }
            if(negative[a[i]]==true)
                negative[b[i]]=true;
        }
    

    if(negative[n])
        cout<<"inf"<<endl;
    else
        cout<<-ans<<endl;
    return 0;
}
