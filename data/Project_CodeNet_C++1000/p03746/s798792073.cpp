#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int main(){
    int n,m; cin>>n>>m;
    vector<int> edge[n+1];
    rep(i,m){
        int a,b; cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    bool vertex[n+1]={};
    deque<int> path;
    path.push_back(1);
    vertex[1]=1;
    bool flg=1;
    while(flg){
        flg=0;
        int from=path.front();
        for(auto e:edge[from]){
            if(!vertex[e]){
                flg=1;
                vertex[e]=1;
                path.push_front(e);
                break;
            }
        }
    }
    flg=1;
    while(flg){
        flg=0;
        int to=path.back();
        for(auto e:edge[to]){
            if(!vertex[e]){
                flg=1;
                vertex[e]=1;
                path.push_back(e);
                break;
            }
        }
    }
    int x=path.size();
    cout<<x<<endl;
    rep(i,x) cout<<path[i]<<(i==x-1?"\n":" ");
    return 0;
}
