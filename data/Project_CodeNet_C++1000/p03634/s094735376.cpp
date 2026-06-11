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

ll visited[100001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector<ii> v[n+1];
    for(int i=1;i<n;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].pb(mp(c,b));
        v[b].pb(mp(c,a));
    }
    int q,k;
    cin>>q>>k;

    for(int i=1;i<=n;i++){
        visited[i]=inf;
    }

    priority_queue<ii,vector<ii>,greater<ii>> pq;

    pq.push({0,k});
    visited[k]=0;

    while(!pq.empty()){
        ll u=pq.top().se;
        ll d=pq.top().fi;
        pq.pop();
        for(int i=0;i<v[u].size();i++){
            if(v[u][i].fi+d<visited[v[u][i].se]){
                pq.push({v[u][i].fi+d,v[u][i].se});
                visited[v[u][i].se]=v[u][i].fi+d;
            }
        }
    }

    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        cout<<visited[x]+visited[y]<<endl;

    }
    return 0;
}
