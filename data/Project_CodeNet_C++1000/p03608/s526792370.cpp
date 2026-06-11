#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,r;
    cin >> n >> m >> r;
    int c[r];
    for(int i=0; i<r; i++){
        cin >> c[i];
        c[i]--;
    }
    sort(c,c+r);
    int d[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j)d[i][j] = 100000000;
            else d[i][j] = 0;
        }
    }
    for(int i=0; i<m; i++){
        int a,b,e;
        cin >> a >> b >> e;
        a--;b--;
        d[a][b] = e;
        d[b][a] = e;
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    int ans = 1000000000;
    do{
        int t = 0;
        for(int i=1; i<r; i++){
            if(d[c[i]][c[i-1]] < 0){
                t = ans;
                break;
            }
            t += d[c[i]][c[i-1]];
        }
        ans = min(t,ans);
    }while(next_permutation(c,c+r));
    cout << ans << endl;
    return 0;
}
