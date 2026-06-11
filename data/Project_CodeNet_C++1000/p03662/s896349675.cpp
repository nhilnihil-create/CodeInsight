#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<map>
using namespace std;
#define rep(i,n) for(int i=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int i=(m);(i)<(n);(i)++)
typedef long long ll;

vector<vector<int> > G;

void dfs(int v,int p,vector<int>& depth){
    if(depth[v]!=-1)return;
    if(p!=-1)depth[v]=depth[p]+1;
    else depth[v]=0;
    for(auto x:G[v]){
        dfs(x,v,depth);
    }
}

int main(){
    int N;cin >> N;
    vector<int> d1(N,-1),d2(N,-1);
    G.resize(N);
    rep(i,N-1){
        int a,b;cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0,-1,d1);
    dfs(N-1,-1,d2);
    
    int fe=0,sn=0;
    for(int i=0;i<N;i++){
        if(d1[i]<=d2[i])fe++;
        else sn++;
    }
    /*
    cout << endl;
    cout << fe << " " << sn << endl;
    cout << "dist" << endl;
    rep(i,N){
        cout << d1[i] << " " << d2[i];
        cout << endl;
    }
    */
    if(fe>sn)cout << "Fennec" << endl;
    else cout << "Snuke" << endl;

    return 0;
}