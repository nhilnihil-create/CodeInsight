#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9+9;
int g[103][103];
int edg[1004][3];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g[i][j] = inf;
        }
        g[i][i] = 0;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++)cin>>edg[i][j];
        g[edg[i][0]][edg[i][1]] = min (edg[i][2],g[edg[i][0]][edg[i][1]]);
        g[edg[i][1]][edg[i][0]] = min (edg[i][2],g[edg[i][1]][edg[i][0]]);
    }
    int ans = m;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    for(int i=0;i<m;i++){
        bool shortest = false;
        for(int j=1;j<=n;j++){
            if(g[j][edg[i][0]]+edg[i][2]==g[j][edg[i][1]])shortest = true;
        }
        if(shortest)ans--;
    }
    cout<<ans<<endl;
    return 0;
}

