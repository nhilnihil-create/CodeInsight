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

int visited[200001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> v[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    int ans=0;
    for(int i=2;i<n;i++){
        int a=0,b=0;
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]==1){
                a=1;
            }
            if(v[i][j]==n){
                b=1;
            }

        }
        if(a==1 && b==1){
            ans=1;
            break;
        }
    }
    if(ans==1){
        cout<<"POSSIBLE"<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
