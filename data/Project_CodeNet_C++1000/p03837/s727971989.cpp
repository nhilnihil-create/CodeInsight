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
    const int inf = 100000000;
    int n,m;
    cin>>n>>m;
    int a[1000],b[1000],c[1000],dist[100][100];

    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--;
        b[i]--;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                dist[i][j]=0;
            else
                dist[i][j]=inf;
        }
    }

    for(int i=0;i<m;i++){
        dist[a[i]][b[i]]=c[i];
        dist[b[i]][a[i]]=c[i];
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    int ans=m;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(dist[j][a[i]]+c[i]==dist[j][b[i]]){
                ans=ans-1;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
