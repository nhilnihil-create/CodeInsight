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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<ii> v;
    vector<ii> c;
    c.pb({0,0});
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.pb({x,y});
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        c.pb({x,y});
    }
    for(int i=0;i<n;i++){
        ll d=abs(c[1].fi-v[i].fi)+abs(c[1].se-v[i].se),index=1;
        for(int j=2;j<=m;j++){
            ll k=abs(c[j].fi-v[i].fi)+abs(c[j].se-v[i].se);
            if(k<d){
                index=j;
                d=k;
            }
        }
        cout<<index<<endl;
    }
    return 0;
}
