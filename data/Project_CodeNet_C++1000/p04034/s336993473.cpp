#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> box(n+1,{1,0});
    box[1][1] = 1;
    for (int i=0; i<m; i++){
        int x, y; cin>>x>>y;
        box[x][0] -= 1; box[y][0] += 1;
        if(box[x][1]==1) box[y][1]=1;
        if(box[x][0]==0) box[x][1]=0;
    }
    int ans = 0;
    for (int i=1; i<=n; i++){
        if (box[i][1]==1) ans ++;
    }
    cout << ans << endl;
}