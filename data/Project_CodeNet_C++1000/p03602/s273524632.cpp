#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll path[300][300];
bool vis[300][300];
int main(){
    int N;
    cin>>N;
    for(int y=0;y<N;y++){
        for(int x=0;x<N;x++){
            cin>>path[y][x];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                if(path[j][k]>path[j][i]+path[i][k]){
                    cout<<-1<<endl;
                    return 0;
                }
                if(path[j][k]==path[j][i]+path[i][k] && !(i==k||i==j)){
                    vis[j][k]=true;
                }
                path[j][k]=min(path[j][k], path[j][i]+path[i][k]);
            }
        }
    }
    ll ans = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(j==i)continue;
            for(int k=0;k<N;k++){
                if(i==k || j==k)continue;
                if(path[i][j]+path[j][k]==path[i][k]){
                    path[i][k]=1145141919;
                    path[k][i]=1145141919;
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            if(!vis[i][j])ans+=path[i][j];
        }
    }
    cout<<ans<<endl;
    return 0;
}