#include <iostream>
#include <vector>
using namespace std;
int d[110][110],e[110][110] = {};
int main(){
    int i,j,k,n,m; cin >> n >> m;
    for(i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        e[a][b] = c; e[b][a] = c;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            d[i][j] = 10000000;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(e[i][j]!=0) d[i][j] = e[i][j];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                d[j][k] = min(d[j][k],d[j][i] + d[i][k]);
            }
        }
    }
    /*for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }*/
    int ans = 0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(e[i][j]>d[i][j]) ans++;
        }
    }
    cout << ans/2 << endl;
}