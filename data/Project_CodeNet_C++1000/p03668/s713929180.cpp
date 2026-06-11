#include<bits/stdc++.h>
using namespace std;

using Graph=vector<vector<int>>;

int grundy(int v,int pre,Graph& g){
    vector<int> gs;
    for(auto to:g[v]){
        if(to!=pre) gs.push_back(grundy(to,v,g)+1);
    }
    int res=0;
    for(auto g:gs) res^=g;
    return res;
} 
int main(){
    int n;
    cin>>n;
    Graph g(n);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cout<<(grundy(0,-1,g) ? "Alice" : "Bob")<<endl;
    return 0;
}