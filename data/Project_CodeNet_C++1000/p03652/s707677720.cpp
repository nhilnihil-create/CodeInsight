#include<bits/stdc++.h>
using namespace std;
int n, m, a[333][333], tong[333];
bool mark[333];
int main(){
    cin>>n>>m;
    for(int i = 1;i <= n; i++){
        for(int j = 1;j <= m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    int ans = n, ma = 0, pos;
    for(int i = 1;i <= n; i++){
        tong[a[i][1]]++;
        if(tong[a[i][1]] > ma){
            ma = tong[a[i][1]];
            pos = a[i][1];
        }
    }
    ans = ma;
    for(int i = 1;i < m; i++){
        mark[pos] = 1; ma = 0;
        memset(tong, 0, sizeof(tong));
        for(int j = 1;j <= n; j++){
            for(int k = 1;k <= m; k++){
                if(!mark[a[j][k]]){
                    tong[a[j][k]]++;
                    if(tong[a[j][k]] > ma){
                        ma = tong[a[j][k]];
                        pos = a[j][k];
                    }
                    break;
                }
            }
        }
        ans = min(ans, ma);
    }
    cout<<ans<<endl;
    return 0;
}
