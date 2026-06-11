#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
int inf=1000000007;
signed main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> map(n+1,vector<int>(n+1,inf));
    rep(i,m){
        int a,b,c;cin>>a>>b>>c;
        map[a][b]=c;
        map[b][a]=c;
    }
    vector<vector<int>> bufmap(map);
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                bufmap[i][j]=min(bufmap[i][j],bufmap[i][k]+bufmap[k][j]);
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(map[i][j]!=inf&&bufmap[i][j]!=map[i][j])res++;
        }
    }
    /*rep1(i,n){
        rep1(j,n){
            cout<<bufmap[i][j]<<"\t";
        }
        cout<<endl;
    }*/
    cout<<res<<endl;
    return 0;
}