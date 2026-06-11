#include<bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
typedef long long ll;
typedef pair<int,pair<int,int>> P;
const ll MOD=1000000007;
const ll INF=1000000010;
const ll LINF=4000000000000000010;
const double EPS=1e-9;
int dx[5]={0,1,0,-1,0};
int dy[5]={1,0,-1,0,0};
vector<int> G[100010];
int dfs(int i,int p){
    int res=0;
    for(auto e:G[i]){
        if(e==p)continue;
        res^=dfs(e,i)+1;
    }
    return res;
}
int main(){
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;x--;y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    if(dfs(0,-1)){
        cout<<"Alice"<<endl;
    }else{
        cout<<"Bob"<<endl;
    }
}
