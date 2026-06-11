#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const int N = 3e2+6;
const int mod = 1e9+7;
const int inf = 1e8;
int g[N][N];
int edg[N*10][3];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g[i][j] = inf;
        }
        g[i][i] = 0;
    }
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edg[i][0] = x;
        edg[i][1] = y;
        edg[i][2] = z;
        g[x][y] = g[y][x] = z;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                g[k][j] = min(g[k][j],g[k][i]+g[i][j]);
            }
        }
    }

    int ans = 0;
    for(int i=0;i<m;i++){
        int x,y,z;
        x = edg[i][0];
        y = edg[i][1];
        z = edg[i][2];
        int shrt = 1;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){

                if(g[j][k]==int(g[j][x]+z+g[y][k]))shrt = 0;
                if(g[j][k]==int(g[j][y]+z+g[x][k]))shrt = 0;
            }
        }
        ans+=shrt;
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)solve();
    return 0;
}
